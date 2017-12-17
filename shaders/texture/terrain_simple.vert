#version 150 core

varying vec3 normal;
varying vec3 position;
varying vec3 light;

uniform vec4 light_position;


void main(void)
{
        gl_TexCoord[0] = gl_MultiTexCoord0;
        gl_TexCoord[1] = gl_TextureMatrix[1] * gl_MultiTexCoord0;

        normal = gl_NormalMatrix * gl_Normal;
        position = (gl_ModelViewMatrix * gl_Vertex).xyz;
        light = (gl_ModelViewMatrix * light_position).xyz;
        gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}

