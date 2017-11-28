#version 400

in vec3 vp;
uniform mat4 modelViewProjection;

void main() {
    gl_Position = modelViewProjection * vec4(vp, 1.0);
}
