#version 330 core

struct DirectionalLight {
  vec3 intensity;
  vec3 direction;
};

struct Transform {
  mat4 projection;
  mat4 inverseView;
  mat4 view;
  mat4 model;
};

in vec3 position;
in vec2 uv;

out vec3 eyeDirV;
out vec3 normalV;
out vec3 normal;
out vec2 uvI;
out float height;
out vec3 positionV;

uniform Transform transform;
uniform DirectionalLight directionallight;
uniform sampler2D displacementTexture;
uniform sampler2D displacementNormal;
uniform float zeroHeight;
uniform float maxDisplacement;
uniform bool shallFixTextureColor = false;

vec3 normalFromMap(vec3 normalColor) {
  const float fix = 0.5f;
  return vec3(
    (normalColor.r - fix) * 2,
    (normalColor.g - fix) * 2,
    normalColor.b
  );
}

vec3 fixTextureColor(vec3 color) {
  if(!shallFixTextureColor) {
    return color;
  }

  return vec3(color.b, color.g, color.r);
}

void main(void)
{
  float displacementColor = texture(displacementTexture, uv).r;
  vec3 normalColor = fixTextureColor(texture(displacementNormal, uv).rgb);
  vec3 n = normalize(normalFromMap(normalColor)).xzy-vec3(0.0f,displacementColor,0.0f);
  //vec3 n = normalColor;
  height = displacementColor;

  float factor = 1;
  float pfactor = 3;
  float nfactor = 1;
  if(zeroHeight > 0.0f) {
    if(zeroHeight > 0.5f) {
        factor = (1.0f - zeroHeight);
    }
    else {
        factor = zeroHeight;
    }
  }

  nfactor = zeroHeight / factor;
  pfactor = (1.0f - zeroHeight) / factor;

  float deltaHeight = 0.0f;
  float alpha = (displacementColor - zeroHeight);
  height = alpha;
  float invfactor = 1 / factor;
  deltaHeight = mix((-nfactor * maxDisplacement) / invfactor, (pfactor * maxDisplacement) / invfactor, displacementColor);

  vec3 modifiedPosition = vec3(position.x, position.y + deltaHeight, position.z);
  mat4 modelView = transform.inverseView * transform.model;
  positionV = vec4(modelView * vec4(modifiedPosition, 1.0)).xyz;

  eyeDirV = -positionV;
  normalV = vec4(modelView * vec4(n, 0.0)).xyz;
  normal = n;

  uvI = uv;

  gl_Position = transform.projection * vec4(positionV,1.0);
}
