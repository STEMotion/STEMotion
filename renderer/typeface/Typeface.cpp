//
// Created by MD Gaziur Rahman Noor on 18/6/25.
//

#include "Typeface.h"

#include <epoxy/gl.h>
#include <iostream>


STEMotion::Typeface::Typeface(const FT_Library &freetype_library, const u8 buffer[], const usize buffer_size) {
    FT_Face face;
    if (FT_New_Memory_Face(freetype_library, buffer, buffer_size, 0, &face)) {
        std::cerr << "Failed to load font" << std::endl;
        throw std::runtime_error("Failed to load font");
    }

    FT_Set_Pixel_Sizes(face, 0, FONTFACE_SIZE);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    for (u8 c = 0; c < 128; c++) {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            std::cerr << "Failed to load character " << c << std::endl;
            throw std::runtime_error("Failed to load character");
        }

        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED,
                     GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        Character character = {texture, glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                               glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top), face->glyph->advance.x};
        characters[c] = character;
    }

    FT_Done_Face(face);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, nullptr, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
void STEMotion::Typeface::render_text(const Shader &shader, const std::string &text, float x, const float y,
                                      const float size, const glm::vec3 color) const {
    const float scale = size / FONTFACE_SIZE;

    shader.use();
    shader.set_bool("isRenderingText", true);
    shader.set_vec3("textColor", color);
    shader.set_int("fontTexture", 0);

    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);

    for (auto c: text) {
        const auto [texture_id, size, bearing, advance] = characters[c];

        const float xpos = x + bearing.x * scale;
        const float ypos = y - (size.y - bearing.y) * scale;

        const float w = size.x * scale;
        const float h = size.y * scale;

        const float vertices[6][4] = {
                {xpos, ypos + h, 0.0f, 0.0f}, {xpos, ypos, 0.0f, 1.0f},     {xpos + w, ypos, 1.0f, 1.0f},

                {xpos, ypos + h, 0.0f, 0.0f}, {xpos + w, ypos, 1.0f, 1.0f}, {xpos + w, ypos + h, 1.0f, 0.0f}};
        glBindTexture(GL_TEXTURE_2D, texture_id);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        x += (advance >> 6) * scale;
    }

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}
