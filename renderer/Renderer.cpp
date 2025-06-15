//
// Created by mdgaziur001 on 3/29/25.
//

#include <epoxy/gl.h>
#include <cmath>

#include "Renderer.h"

namespace STEMotion {
    void render_draw_queue(DrawQueue &draw_queue, const f64 time) {
        auto r = 1.0f;
        auto g = std::cos(time);
        auto b = std::sin(time);

        glClearColor(r, g, b, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glFlush();
    }
} // STEMotion