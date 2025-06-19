//
// Created by MD Gaziur Rahman Noor on 16/6/25.
//

#pragma once

#include <string>
#include <glm/glm.hpp>


#include "LibSTEMotion/utils/numsize.h"

namespace STEMotion {
    class Shader {
        usize shader_obj_ref;
    public:
        Shader(const std::string& vert_shader_path, const std::string& vert_shader_src, const std::string &frag_shader_path, const std::string& frag_shader_src);
        [[nodiscard]] usize get_shader_obj_ref() const {
            return shader_obj_ref;
        }
        void use() const;
        void set_float(const std::string &name, f32 value) const;
        void set_bool(const std::string &name, bool value) const;
        void set_int(const std::string &name, i32 value) const;
        void set_vec3(const std::string &name, glm::vec3 value) const;
        void set_mat4(const std::string &name, glm::mat4 value, bool transpose) const;
        ~Shader();
    };
}
