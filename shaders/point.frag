/*
 * fragment shader for phong + textures + bumps
 *
 */

#version 150

// output - transformed to eye coordinates (EC)

// output: fragment/pixel color
out vec4 outColor;
uniform sampler2D sprite_texture;


void main() {
   // outColor = texture(sprite_texture, gl_PointCoord);
    const vec4 color1 = vec4(0.6, 0.0, 0.0, 1.0);
    const vec4 color2 = vec4(0.9, 0.7, 1.0, 0.0);
    vec2 temp = gl_PointCoord - vec2(0.5);
    float f = dot(temp, temp);

    if (f > 0.25)
    discard;

    outColor = mix(color1, color2, smoothstep(0.1, 0.25, f));
}
