#version 330 core

struct DirectionalLight {
  vec3 intensity;
  vec3 direction;
};

in vec3 positionV;
in vec3 eyeDirV;
in vec3 normalV;
in vec3 waveColor;
in vec3 normalBeforeWaves;
in vec2 uvI;
in vec3 positionW;
in vec3 eyePosW;
in vec3 normalW;
const bool usePhong = true;

uniform DirectionalLight directionallight;
uniform bool reflectionEnable;
uniform float elapsed;
uniform samplerCube cubeMap;
uniform float ka = 0.8f;
uniform float kd = 0.4f;
uniform float ks = 1.0f;
uniform float shininess = 128.0f;
uniform float fogDistance = 0.9978f;
uniform float fogPow = 15.00f;
uniform bool shallFixTextureColor = false;

out vec4 color;

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
  vec3 NW = normalize(normalW);
  vec3 N = normalize(normalV);
  vec3 E = normalize(eyeDirV);
  vec3 L = normalize(-directionallight.direction);
  vec3 Ereflection = normalize(positionW - eyePosW);

  if(usePhong) {
    vec3 waterColor = waveColor;
    vec3 mixedNormal = normalize(mix(normalBeforeWaves, NW, 0.005));

    if(reflectionEnable) {
      vec3 reflectionColor = fixTextureColor(texture(cubeMap, normalize(reflect(Ereflection, mixedNormal))).rgb);
      waterColor = mix(waveColor, reflectionColor, vec3(0.5));
    }

    vec3 phongMixedNormal = normalize(mix(normalBeforeWaves, NW, 0.8));

    vec3 phong = ka * waterColor;
    phong += kd * directionallight.intensity * waterColor * max(0.0, dot(NW, L));
    phong += ks * directionallight.intensity * pow(max(0.0, dot(reflect(-E, phongMixedNormal), L)), shininess);
    color.rgb = phong;
    color.a = clamp(1 - dot(-Ereflection, mixedNormal), 0.25, 0.95);

  }
  else
    color = vec4(waveColor, 1);

  color.rgb = applyFog(color.rgb);
}
