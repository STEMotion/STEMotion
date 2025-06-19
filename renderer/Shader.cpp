//
// Created by MD Gaziur Rahman Noor on 16/6/25.
//

#include "Shader.h"

#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include <epoxy/gl.h>

static usize load_shader(const std::string &shader_path, const std::string &shader_src, const GLenum type) {
    const usize shader_obj_ref = glCreateShader(type);
    const char *src = shader_src.c_str();
    glShaderSource(shader_obj_ref, 1, &src, nullptr);
    glCompileShader(shader_obj_ref);

    i32 success;
    char info_log[512];
    glGetShaderiv(shader_obj_ref, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader_obj_ref, 512, nullptr, info_log);
        std::cerr << "[FATAL] Failed to compile shader: " << shader_path << std::endl;
        std::cerr << info_log << std::endl;
        throw std::runtime_error("Failed to compile shader");
    }

    return shader_obj_ref;
}

namespace STEMotion {
    Shader::Shader(const std::string &vert_shader_path, const std::string &vert_shader_src,
                   const std::string &frag_shader_path, const std::string &frag_shader_src) {
        const usize vert_shader_ref = load_shader(vert_shader_path, vert_shader_src, GL_VERTEX_SHADER);
        const usize frag_shader_ref = load_shader(frag_shader_path, frag_shader_src, GL_FRAGMENT_SHADER);

        shader_obj_ref = glCreateProgram();
        glAttachShader(shader_obj_ref, vert_shader_ref);
        glAttachShader(shader_obj_ref, frag_shader_ref);
        glLinkProgram(shader_obj_ref);

        i32 success;
        char info_log[512];
        glGetProgramiv(shader_obj_ref, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader_obj_ref, 512, nullptr, info_log);
            std::cerr << "[FATAL] Failed to link shader" << std::endl;
            std::cerr << info_log << std::endl;
            throw std::runtime_error("Failed to link shader");
        }

        glDeleteShader(vert_shader_ref);
        glDeleteShader(frag_shader_ref);
    }

    void Shader::use() const {
        glUseProgram(shader_obj_ref);
    }

    void Shader::set_float(const std::string &name, const GLfloat value) const {
        glUniform1f(glGetUniformLocation(shader_obj_ref, name.c_str()), value);
    }

    void Shader::set_bool(const std::string &name, const bool value) const {
        glUniform1i(glGetUniformLocation(shader_obj_ref, name.c_str()), value);
    }

    void Shader::set_int(const std::string &name, const GLint value) const {
        glUniform1i(glGetUniformLocation(shader_obj_ref, name.c_str()), value);
    }

    void Shader::set_vec3(const std::string &name, glm::vec3 value) const {
        glUniform3f(glGetUniformLocation(shader_obj_ref, name.c_str()), value[0], value[1], value[2]);
    }

    void Shader::set_mat4(const std::string &name, glm::mat4 value, const bool transpose) const {
        glUniformMatrix4fv(glGetUniformLocation(shader_obj_ref, name.c_str()), 1, transpose, glm::value_ptr(value));
    }

    Shader::~Shader() {
        glDeleteProgram(shader_obj_ref);
    }
}
