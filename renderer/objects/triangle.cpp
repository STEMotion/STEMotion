//
// Created by MD Gaziur Rahman Noor on 16/6/25.
//

#include "LibSTEMotion/renderer/Object.h"

#include <epoxy/gl.h>

#include "../Shader.h"
#include "object.h"

void STEMotion::draw_triangle(const Triangle &triangle, const Shader &shader, f32 x0, f32 y0) {
    const f32 vertices[] = {
            triangle.x1 + x0, triangle.y1 + y0, 0.0f,
            triangle.x2 + x0, triangle.y2 + y0, 0.0f,
            triangle.x3 + x0, triangle.y3 + y0, 0.0f,
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(f32), (void*)0);
    glEnableVertexAttribArray(0);

    shader.use();
    shader.set_bool("isRenderingText", false);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
