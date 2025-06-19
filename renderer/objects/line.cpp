//
// Created by MD Gaziur Rahman Noor on 16/6/25.
//

#include "../Shader.h"
#include "LibSTEMotion/renderer/Object.h"
#include "object.h"

#include <epoxy/gl.h>

void STEMotion::draw_line(const Line &line, const Shader &shader, f32 x0, f32 y0) {
    f32 vertices[] = {
        line.x1 + x0, line.y1 + y0, 0.0f,
        line.x2 + x0, line.y2 + y0, 0.0f,
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(f32), (void *)0);

    shader.use();
    shader.set_bool("isRenderingText", false);
    glDrawArrays(GL_LINES, 0, 2);
}