//
// Created by MD Gaziur Rahman Noor on 16/6/25.
//

#include <iostream>
#include <vector>


#include "../Shader.h"
#include "LibSTEMotion/renderer/Object.h"
#include "object.h"

#include <epoxy/gl.h>

void STEMotion::draw_circle(const Circle &circle, const Shader &shader, f32 x0, f32 y0) {
    const f32 radius = circle.radius;
    const f32 circumference = 2.0f * M_PI * radius;
    const usize vertices_count = circumference * 100;
    const f32 theta = 2.0f * M_PI / vertices_count;

    std::vector<f32> vertices((vertices_count + 1) * 3);
    vertices[0] = x0;
    vertices[1] = y0;
    vertices[2] = 0.0f;

    for (i32 i = 1; i <= vertices_count; i++) {
        vertices[3 * i] = x0 + radius * cos(theta * i);
        vertices[3 * i + 1] = y0 + radius * sin(theta * i);
        vertices[3 * i + 2] = 0.0f;
    }

    std::vector<unsigned int> indices;
    for (i32 i = 1; i < vertices_count; i++) {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back(i + 1);
    }

    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(vertices_count);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(f32), vertices.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(f32), (void*)0);

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    shader.use();
    shader.set_bool("isRenderingText", false);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}
