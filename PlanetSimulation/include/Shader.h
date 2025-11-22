#pragma once
#include <string>
#include "../glm/glm.hpp"

// Shader类，目前opengl最干净的实现
class Shader
{
public:
    unsigned int ID;
    Shader();
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void Use() const;

    // 根据不同参数重载SetUniform
    void SetUniform(const std::string& name, float value) const;
    void SetUniform(const std::string& name, int value) const;
    void SetUniform(const std::string& name, const glm::vec2& value) const;
    void SetUniform(const std::string& name, const glm::vec3& value) const;
    void SetUniform(const std::string& name, const glm::vec4& value) const;
    void SetUniform(const std::string& name, const glm::mat4& mat) const;

private:
    std::string LoadFile(const std::string& path) const;
    unsigned int CompileShader(unsigned int type, const std::string& source);
    unsigned int LinkProgram(unsigned int vs, unsigned int fs);
};
