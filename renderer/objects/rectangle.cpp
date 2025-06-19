//
// Created by MD Gaziur Rahman Noor on 16/6/25.
//

#include "../Shader.h"
#include "LibSTEMotion/renderer/Object.h"
#include "object.h"

#include <epoxy/gl.h>

void STEMotion::draw_rectangle(const Rectangle &quad, const Shader &shader, f32 x0, f32 y0) {
    const f32 half_height = quad.height * 0.5f;
    const f32 half_width = quad.width * 0.5f;
    const f32 vertices[] = {
        half_height + x0, half_width + y0, 0.0f,
        half_height + x0, -half_width + y0, 0.0f,
        -half_height + x0, -half_width + y0, 0.0f,
        -half_height + x0, half_width + y0, 0.0f,
    };
    const unsigned int indices[] = {
        0, 1, 2,
        0, 2, 3,
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(f32), (void*)0);

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    shader.use();
    shader.set_bool("isRenderingText", false);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
