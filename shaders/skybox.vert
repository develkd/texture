#version 150 core

struct Transform {
  mat4 projection;
  mat4 inverseView;
  mat4 view;
  mat4 model;
};

in vec3 position;
in vec2 uv;

out vec3 positionFragment;
out vec2 uvI;

uniform Transform transform;
uniform sampler2D planeTexture;

void main(void)
{
  mat4 modelView = transform.inverseView * transform.model;
  vec4 positionV = modelView * vec4(position, 1.0);

  positionFragment = position;

  uvI = uv;

  gl_Position = transform.projection * positionV;
}
