#version 430

varying vec3 vertex_light_position;
varying vec3 vertex_normal;
varying vec3 vertex_colour;

out vec4 frag_colour;

void main() {
    float diffuse_value = max(dot(vertex_normal, vertex_light_position), 0.0);
    frag_colour = vec4(0.5, 0.0, 0.5, 1.0) * diffuse_value;
}
