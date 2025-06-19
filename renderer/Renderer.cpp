//
// Created by mdgaziur001 on 3/29/25.
//

#include <cmath>
#include <epoxy/gl.h>

#include "Renderer.h"

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <iostream>

#include "font/font_bold.h"
#include "font/font_italic.h"
#include "font/font_regular.h"
#include "objects/object.h"

constexpr char VERTEX_SHADER[] = (
#include "shaders/vertex.vert"


);

constexpr char FRAGMENT_SHADER[] = (
#include "shaders/fragment.frag"


);

namespace STEMotion {
    Renderer::Renderer() {
        FT_Library freetype_library;
        if (FT_Init_FreeType(&freetype_library)) {
            std::cerr << "Failed to initialize freetype library" << std::endl;
            throw std::runtime_error("Failed to initialize freetype library");
        }

        typeface_regular = new Typeface(freetype_library, font_regular, std::size(font_regular));
        typeface_italic = new Typeface(freetype_library, font_italic, std::size(font_italic));
        typeface_bold = new Typeface(freetype_library, font_bold, std::size(font_bold));

        FT_Done_FreeType(freetype_library);

        shader = new Shader("shaders/vertex.vert", VERTEX_SHADER, "shaders/fragment.frag", FRAGMENT_SHADER);
    }

    Renderer::~Renderer() {
        delete typeface_regular;
        delete typeface_italic;
        delete typeface_bold;
    }


    void Renderer::render_draw_queue(DrawQueue &draw_queue, const f64 time, const f32 width, const f32 height) const {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        const auto ortho_matrix = glm::ortho(0.0f, width, 0.0f, height);
        shader->set_mat4("projection", ortho_matrix, false);

        while (!draw_queue.empty()) {
            switch (auto draw_command = draw_queue.pop_command(); draw_command.kind) {
                case ObjectKindTriangle:
                    draw_triangle(draw_command.triangle, *shader, draw_command.x0, draw_command.y0);
                    break;
                case ObjectKindLine:
                    draw_line(draw_command.line, *shader, draw_command.x0, draw_command.y0);
                    break;
                case ObjectKindRectangle:
                    draw_rectangle(draw_command.rectangle, *shader, draw_command.x0, draw_command.y0);
                    break;
                case ObjectKindCircle:
                    draw_circle(draw_command.circle, *shader, draw_command.x0, draw_command.y0);
                    break;
                case ObjectKindText:
                    typeface_italic->render_text(*shader, draw_command.text.text, draw_command.x0, draw_command.y0,
                                                 draw_command.text.size, glm::vec3(1.0f));
                    break;
            }
        }

        glFlush();
    }
} // namespace STEMotion
