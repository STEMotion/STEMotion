//
// Created by mdgaziur001 on 3/29/25.
//

#pragma once

#include <LibSTEMotion/renderer/DrawQueue.h>
#include <LibSTEMotion/utils/numsize.h>
#include <freetype/freetype.h>

#include "Shader.h"
#include "typeface/Typeface.h"

namespace STEMotion {

    class Renderer {
    public:
        Renderer();
        ~Renderer();
        // TODO: implement this properly
        void render_draw_queue(DrawQueue &draw_queue, const f64 time, const f32 width, const f32 height) const;

    private:
        Shader *shader;
        Typeface *typeface_bold;
        Typeface *typeface_italic;
        Typeface *typeface_regular;
    };

} // namespace STEMotion
