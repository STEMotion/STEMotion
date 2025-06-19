R""(

#version 330 core
in vec2 TexCoords;
out vec4 FragColor;

uniform bool isRenderingText;
uniform sampler2D fontTexture;
uniform vec3 textColor;

void main() {
    if (isRenderingText) {
        vec4 sampled = vec4(1.0, 1.0, 1.0, texture(fontTexture, TexCoords).r);
        FragColor = vec4(textColor, 1.0) * sampled;
    } else {
        FragColor = vec4(1.0f);
    }
}

)""