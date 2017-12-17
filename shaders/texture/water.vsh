
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
in vec3 normal;
in vec2 uv;

out vec3 positionV;
out vec3 positionW;
out vec3 eyePosW;
out vec3 normalW;
out vec3 eyeDirV;
out vec3 normalV;
out vec3 waveColor;
out vec3 normalBeforeWaves;
out vec2 uvI;

uniform Transform transform;
uniform DirectionalLight directionallight;
uniform vec2 uvOffset;
uniform float time;
uniform float scaleFactor;
uniform float waveHeightFactor;
uniform float waveLengthFactor;
uniform float waveSpeedFactor;
uniform bool waveEnable;
uniform bool radialMode = false;

//const float time = 1.5;

const float pi = 3.1415;
const int numWaves = 8;
float amplitude[8] = float[](
    scaleFactor * waveHeightFactor * 0.00001,
    scaleFactor * waveHeightFactor * 0.00002,
    scaleFactor * waveHeightFactor * 0.0000121,
    scaleFactor * waveHeightFactor * 0.00005,
    scaleFactor * waveHeightFactor * 0.00001,
    scaleFactor * waveHeightFactor * 0.00000011,
    scaleFactor * waveHeightFactor * 0.0000008,
    scaleFactor * waveHeightFactor * 0.0000009
);

float wavelength[8] = float[](
    scaleFactor * waveLengthFactor * 0.55 * 2,
    scaleFactor * waveLengthFactor * 0.2 * 2,
    scaleFactor * waveLengthFactor * 0.39 * 2,
    scaleFactor * waveLengthFactor * 0.93 * 2,
    scaleFactor * waveLengthFactor * 0.57 * 2,
    scaleFactor * waveLengthFactor * 0.055 * 2,
    scaleFactor * waveLengthFactor * 0.04 * 2,
    scaleFactor * waveLengthFactor * 0.063 * 2
);

float speed[8]  = float[](
    scaleFactor * waveSpeedFactor * 0.04,
    scaleFactor * waveSpeedFactor * 0.06,
    scaleFactor * waveSpeedFactor * 0.041,
    scaleFactor * waveSpeedFactor * 0.043,
    scaleFactor * waveSpeedFactor * 0.025,
    scaleFactor * waveSpeedFactor * 0.08,
    scaleFactor * waveSpeedFactor * 0.1,
    scaleFactor * waveSpeedFactor * 0.11
);

vec2 direction[8]  = vec2[](
    vec2(1,1),
    vec2(0.25,1),
    vec2(1,0.75),
    vec2(-0.7,0.75),
    vec2(0.25,1),
    vec2(0.3,0.5),
    vec2(0.7,0.6),
    vec2(0.625,0.6)
);

float maxAmplitude = scaleFactor * 0.005;

const vec3 darkWave = vec3(0.063, 0.22, 0.278);
const vec3 brightWave = darkWave * 2;

vec2 uvfix;

float wave(int i, vec2 xz) {
    float frequency = 2*pi/wavelength[i];
    float phase = speed[i] * frequency;
    float theta;
    if(radialMode) {
      theta = length(direction[i] - uvfix);
    } else {
      theta = dot(direction[i], xz);
    }

    return amplitude[i] * sin(theta * frequency + time * phase);
}

float dWavedx(int i, vec2 xz) {
    float frequency = 2*pi/wavelength[i];
    float phase = speed[i] * frequency;
    float theta;
    if(radialMode) {
      theta = 2000*length(direction[i] - uvfix);
    } else {
      theta = dot(direction[i], xz);
    }
    float A = amplitude[i] * direction[i].x * frequency;
    return A * cos(theta * frequency + time * phase);
}

float dWavedz(int i, vec2 xz) {
    float frequency = 2*pi/wavelength[i];
    float phase = speed[i] * frequency;
    float theta;
    if(radialMode) {
      theta = 2000*length(direction[i] - uv);
    } else {
      theta = dot(direction[i], xz);
    }
    float A = amplitude[i] * direction[i].y * frequency;
    return A * cos(theta * frequency + time * phase);
}

void fixUv() {
  uvfix = vec2(
    (uv.x + uvOffset.x) - int(uv.x + uvOffset.x),
    (uv.y + uvOffset.y) - int(uv.y + uvOffset.y)
  );

  if(uvfix.x < 0) {
    uvfix.x = 1 - uvfix.x;
  }

  if(uvfix.y < 0)  {
    uvfix.y = 1 - uvfix.y;
  }
}

void main(void)
{
  vec3 n = vec3(0,1,0);
  mat4 modelView = transform.inverseView * transform.model;
  normalBeforeWaves = n;
  positionV = vec4(modelView * vec4(position, 1)).xyz;
  eyePosW = transform.view[3].xyz;
  positionW = vec3(transform.model * vec4(position, 1.0));
  normalW = vec3(transform.model * vec4(n, 0.0));

  if(waveEnable) {

    float y = position.y;
    float dx = 0.0;
    float dz = 0.0;

  //  for (int i = 0; i < numWaves; ++i) {
  //      y += wave(i, position.xz);
  //      dx += dWavedx(i, position.xz);
  //      dz += dWavedz(i, position.xz);
  //  }

    y += wave(0, position.xz);
    dx += dWavedx(0, position.xz);
    dz += dWavedz(0, position.xz);

    y += wave(1, position.xz);
    dx += dWavedx(1, position.xz);
    dz += dWavedz(1, position.xz);

    y += wave(2, position.xz);
    dx += dWavedx(2, position.xz);
    dz += dWavedz(2, position.xz);

    y += wave(3, position.xz);
    dx += dWavedx(3, position.xz);
    dz += dWavedz(3, position.xz);

    y += wave(4, position.xz);
    dx += dWavedx(4, position.xz);
    dz += dWavedz(4, position.xz);

    y += wave(5, position.xz);
    dx += dWavedx(5, position.xz);
    dz += dWavedz(5, position.xz);

    y += wave(6, position.xz);
    dx += dWavedx(6, position.xz);
    dz += dWavedz(6, position.xz);

    y += wave(7, position.xz);
    dx += dWavedx(7, position.xz);
    dz += dWavedz(7, position.xz);

    float yoffset = y - position.y;
    float alpha = (yoffset + maxAmplitude) / (2*maxAmplitude);
    waveColor = mix(darkWave, brightWave, alpha);
    n = normalize(vec3(-dx , waveHeightFactor * 0.00075, -dz));
    //waveColor = n;
    //n = vec3(0,1,0);

    positionV = vec3(modelView * vec4(position.x, y, position.z, 1.0));
    positionW = vec3(transform.model * vec4(position.x, y, position.z, 1.0));
    normalW = vec3(transform.model * vec4(n, 0.0f));
  }
  else {
    waveColor = darkWave;
  }

  eyeDirV = -positionV.xyz;
  normalV = vec4(modelView * vec4(n, 0.0)).xyz;
  uvI = uv;

  gl_Position = transform.projection * vec4(positionV,1.0);
}
