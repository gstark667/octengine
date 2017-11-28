#version 430

in vec3 vp;
in vec3 vn;

uniform mat4 modelViewProjection;

varying vec3 vertex_light_position;
varying vec3 vertex_normal;
varying vec3 vertex_colour;

void main() {
    vertex_normal = normalize(vec4(vn, 1.0)).xyz;
    vertex_colour = vec3(vp.xyz);
    vertex_light_position = normalize(vec3(5, 5, 5));
    gl_Position = modelViewProjection * vec4(vp, 1.0);
}
