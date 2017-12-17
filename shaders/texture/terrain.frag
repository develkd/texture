#version 330 core

struct Transform {
    mat4 projection;
    mat4 inverseView;
    mat4 view;
    mat4 model;
};

struct DirectionalLight {
    vec3 intensity;
    vec3 direction;
};

in vec3 positionV;
in vec3 eyeDirV;
in vec3 normalV;
in vec3 normal;
in vec2 uvI;
in float height;

out vec4 color;

const float ka = 0.3;
const float kd = 0.8;
const float ks = 0.0;
const float ke = 128.0;
const bool showNormal = false;

uniform Transform transform;
uniform vec2 uvTiles;
uniform DirectionalLight directionallight = DirectionalLight(vec3(1),vec3(1));
uniform sampler2D grassTexture;
uniform sampler2D underwaterTexture;
uniform sampler2D beachTexture;
uniform sampler2D rockTexture;
uniform float fogDistance = 0.9978f;
uniform float fogPow = 15.00f;
uniform bool shallFixTextureColor = false;

vec3 fixTextureColor(vec3 color) {
  if(!shallFixTextureColor) {
    return color;
  }

  return vec3(color.b, color.g, color.r);
}

vec3 applyFog(vec3 color) {
    float fResult = exp(-pow((1-fogDistance)*length(positionV), fogPow));
    fResult = 1.0-clamp(fResult, 0.0, 1.0);
    return fResult * vec3(0.9) + (1-fResult) * color;
}

void main(void)
{
    vec3 N = normalize(normalV);
    vec3 E = normalize(eyeDirV);
    vec3 L = normalize(transform.inverseView * vec4(-directionallight.direction,0)).xyz;

    vec2 uvFinal = vec2(uvI.x * uvTiles.x,uvI.y * uvTiles.y);
    uvFinal.x -= int(uvFinal.x);
    uvFinal.y -= int(uvFinal.y);

    vec3 grassColor = fixTextureColor(texture(grassTexture, uvFinal).xyz);
    vec3 underwaterColor = fixTextureColor(texture(underwaterTexture, uvFinal).xyz);
    vec3 beachColor = fixTextureColor(texture(beachTexture, uvFinal).xyz);
    vec3 rockColor = fixTextureColor(texture(rockTexture, uvFinal).xyz);
    vec3 groundColor;

    if(height < -0.03f) {
      groundColor = underwaterColor;
      //groundColor = vec3(0.0f, 1.0f, 1.0f);
    }
    else if(height >= -0.03f && height < -0.02f) {
      float alpha = (-0.03f - height) * 100.0f + 1.0f;
      groundColor = mix(beachColor, underwaterColor, alpha);
      //groundColor = vec3(1.0f, 0.0f, 1.0f);
    }
    else if(height >= -0.02f && height < 0.01f) {
      groundColor = beachColor;
      //groundColor = vec3(0.0f, 0.0f, 0.5f);
    }
    else if(height >= 0.01f && height < 0.04f) {
      float alpha = ((0.04f - height)/3) * 100.0f;
      groundColor = mix(grassColor, beachColor, alpha);
      //groundColor = vec3(1.0f, 0.0f, 0.0f);
    }
    else if(height >= 0.04f && height < 0.05f) {
      groundColor = grassColor;
    }
    else {
      float phi = abs(dot(normal, vec3(0.0, 1.0, 0.0)));
      phi = clamp(phi, 0.0f, 1.0f);

      vec3 hillColor;
      if(phi <= 0.4f) {
          hillColor = grassColor;
      }
      else if(phi >= 0.6f) {
          hillColor = rockColor;
      }
      else {
          float alpha = ((0.6f - phi) / 2) * 10.0f;
          hillColor = mix(rockColor, grassColor, alpha);
      }

      //vec3 hillColor = mix(vec3(1.0f, 0.0f, 0.f), vec3(0.0f, 1.0f, 0.0f), phi);
      float alpha = clamp(((0.09f - height)/4) * 100.0f, 0.0f, 1.0f);
      groundColor = mix(hillColor, grassColor, alpha);
      //groundColor = vec3(1.0f, 1.0f, 0.0f);
      //groundColor = vec3(phi,0.0,0.0);
    }


    color.rgb = groundColor;
    //groundColor = grassColor;
    color.a = 1;
    if(!showNormal) {


        // Ambient
        vec3 col = ka * groundColor * directionallight.intensity;
        // Diffuse
        col += kd * groundColor * directionallight.intensity * max(0.0, dot(N, L));
        // Specular
        if (ke > 0.0) {
            col += ks * directionallight.intensity * pow(max(0.0, dot(E, -reflect(L, N))), ke);
        }

        color.rgb = applyFog(col);


    }
    else {
        color.rgb = normal;
    }
}
