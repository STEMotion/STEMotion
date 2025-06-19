R""(

#version 330 core
layout (location = 0) in vec4 vertex;
out vec2 TexCoords;

uniform bool isRenderingText;
uniform mat4 projection;

void main() {
    if (isRenderingText) {
        gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);
        TexCoords = vertex.zw;
    } else {
        gl_Position = projection * vec4(vertex.xyz, 1.0f);
    }
}

)""