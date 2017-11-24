/*
 * fragment shader
 *
 */

#version 150
struct PhongMaterial {
    vec3 k_ambient;
    vec3 k_diffuse;
    vec3 k_specular;
    float shininess;

};
struct PointLight {
    vec3 intensity;
    vec4 position_WC;
    int  pass;
};

struct ToonShader {
   bool toon;
};

// output - transformed to eye coordinates (EC)
in vec4 position_EC;
in vec3 normal_EC;
in vec2 fragTextCoord;
// output: fragment/pixel color
out vec4 outColor;


uniform PhongMaterial phong;
uniform vec3 ambientLightIntensity;


uniform ToonShader toonShader;
uniform PointLight light;

uniform mat4 viewMatrix;
uniform vec3 color;
uniform vec3 lightIntensity;


/*
 *  Calculate surface color based on Phong illumination model.
 */

vec3 myphong(vec3 n, vec3 v, vec3 l) {

    // cosine of angle between light and surface normal.
    float ndotl = dot(n,l);

    // ambient / emissive part
    vec3 ambient = vec3(0,0,0);
    if(light.pass == 0) // only add ambient in first light pass
        ambient = phong.k_ambient * ambientLightIntensity;

    // surface back-facing to light?
    if(ndotl<=0.0)
        return ambient;
    else
        ndotl = max(ndotl, 0.0);

    // diffuse term
    vec3 diffuse =  phong.k_diffuse * light.intensity * ndotl;

    // reflected light direction = perfect reflection direction
    vec3 r = reflect(-l,n);

    // cosine of angle between reflection dir and viewing dir
    float rdotv = max( dot(r,v), 0.0);

    // specular contribution + gloss map
    vec3 specular = phong.k_specular * light.intensity * pow(rdotv, phong.shininess);

    // return sum of all contributions
    return ambient + diffuse + specular;

}



vec3 getTextureColor(vec3 phong_color) {
    int density = 5;
    float radius = 0.12;

            vec2 middle = vec2(0.5, 0.5);
            middle = middle / density;

            float localRadius = radius / density;
            float x1_y1 = 1.0 / density;

            middle = vec2(
                    float(int(fragTextCoord.x/x1_y1)) * x1_y1 + middle.x,
                    float(int(fragTextCoord.y/x1_y1)) * x1_y1 + middle.y);

            if (distance(fragTextCoord, middle) < localRadius) {
                return  phong_color-vec3(0.2, 0.3, 0.4);
            }
            else {
                return phong_color;
            }
        }

void main() {

    // calculate all required vectors in camera/eye coordinates
    vec4 lightpos_EC = viewMatrix * light.position_WC;
    vec3 lightdir_EC = (lightpos_EC   - position_EC).xyz;
    vec3 viewdir_EC  = (vec4(0,0,0,1) - position_EC).xyz;

   vec3 phong_color =  myphong(normalize(normal_EC),
                           normalize(viewdir_EC),
                           normalize(lightdir_EC));
    outColor = vec4( getTextureColor(phong_color),1);

}
