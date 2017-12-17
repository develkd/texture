#version 330 core

in vec3 position_MC;
in vec2 texcoord;
in vec3 normal_MC;

in vec3 tangent_MC;
in vec3 bitangent_MC;

out vec2 pass_textureCoordinates;
out vec3 surfaceNormal;
out vec3 toLightVector;
out vec3 toCameraVector;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform vec3 lightPosition;

void main(void){

        vec4 worldPosition = transformationMatrix * vec4(position_MC,1.0);
        gl_Position = projectionMatrix * viewMatrix * worldPosition;
        pass_textureCoordinates = texcoord;

        surfaceNormal = (transformationMatrix * vec4(normal_MC,0.0)).xyz;
        toLightVector = lightPosition - worldPosition.xyz;
        toCameraVector = (inverse(viewMatrix) * vec4(0.0,0.0,0.0,1.0)).xyz - worldPosition.xyz;


}
