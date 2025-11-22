#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>

Shader::Shader()
{
}

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
    std::string vsSource = LoadFile(vertexPath);
    std::string fsSource = LoadFile(fragmentPath);

    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vsSource);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fsSource);

    ID = LinkProgram(vs, fs);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

void Shader::Use() const
{
    glUseProgram(ID);
}

std::string Shader::LoadFile(const std::string& path) const
{
    std::ifstream file(path);
    std::stringstream buf;
    buf << file.rdbuf();
    return buf.str();
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
    unsigned int shader = glCreateShader(type);
    const char* src = source.c_str();

    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char infoLog[1024];
        glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
        std::cerr << "Shader compile error:\n" << infoLog << std::endl;
    }

    return shader;
}

unsigned int Shader::LinkProgram(unsigned int vs, unsigned int fs)
{
    unsigned int program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success)
    {
        char infoLog[1024];
        glGetProgramInfoLog(program, 1024, nullptr, infoLog);
        std::cerr << "Program link error:\n" << infoLog << std::endl;
    }

    return program;
}

// ------- uniform helpers -------
void Shader::SetUniform(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetUniform(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetUniform(const std::string& name, const glm::vec2& v) const
{
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &v[0]);
}

void Shader::SetUniform(const std::string& name, const glm::vec3& v) const
{
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &v[0]);
}

void Shader::SetUniform(const std::string& name, const glm::vec4& v) const
{
    glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &v[0]);
}

void Shader::SetUniform(const std::string& name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
