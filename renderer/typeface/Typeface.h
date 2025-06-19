//
// Created by MD Gaziur Rahman Noor on 18/6/25.
//

#ifndef TYPEFACE_H
#define TYPEFACE_H
#include <freetype/freetype.h>
#include <glm/vec2.hpp>

#include "../Shader.h"
#include "LibSTEMotion/utils/numsize.h"

namespace STEMotion {
    constexpr usize FONTFACE_SIZE = 512;

    class Typeface {
        struct Character {
            unsigned int texture_id;
            glm::ivec2 size;
            glm::ivec2 bearing;
            signed long advance;
        };

        Character characters[128];
        unsigned int VAO;
        unsigned int VBO;

    public:
        Typeface(const FT_Library &freetype_library, const u8 buffer[], const usize buffer_size);
        void render_text(const Shader &shader, const std::string& text, float x, float y, float size, glm::vec3 color) const;
    };
}



#endif //TYPEFACE_H
