#version 330 core


in vec2 uvI;
in vec3 positionFragment;

out vec4 color;

uniform bool shallFixTextureColor = false;

const bool useTexture = true;
uniform samplerCube cubeTexture;

vec3 fixTextureColor(vec3 color) {
  if(!shallFixTextureColor) {
    return color;
  }

  return vec3(color.b, color.g, color.r);
}

void main(void)
{
  if(useTexture) {
    vec3 fragmentColor = fixTextureColor(texture(cubeTexture, normalize(positionFragment)).xyz);

    color.rgb = fragmentColor.rgb;
    color.a = 1;
  }
  else
    color = vec4(0.59, 0.93, 0.87, 1);
}
