//
// Created by MD Gaziur Rahman Noor on 16/6/25.
//

#pragma once

namespace STEMotion {
    void draw_triangle(const Triangle &triangle, const Shader &shader, f32 x0, f32 y0);
    void draw_rectangle(const Rectangle &quad, const Shader &shader, f32 x0, f32 y0);
    void draw_circle(const Circle &circle, const Shader &shader, f32 x0, f32 y0);
    void draw_line(const Line &line, const Shader &shader, f32 x0, f32 y0);
}
