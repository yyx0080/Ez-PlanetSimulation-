#include "Rendered2D.h"
#include <iostream>
Renderer2D::Renderer2D()
{
    Shader lineShader = Shader("shaders/line.vert", "shaders/line.frag");
    // ----------- 初始化 VAO / VBO -----------
    glGenVertexArrays(1, &lineVAO);
    glGenBuffers(1, &lineVBO);

    glBindVertexArray(lineVAO);
    glBindBuffer(GL_ARRAY_BUFFER, lineVBO);
    // 先开辟最大大小（两个 vec2）
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4, nullptr, GL_DYNAMIC_DRAW);
    // 设置顶点格式 (location=0, vec2)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0,            // layout(location = 0)
        2,            // vec2
        GL_FLOAT,
        GL_FALSE,
        sizeof(float) * 2,
        (void*)0
    );

    glBindVertexArray(0);
}

Renderer2D::~Renderer2D()
{
    glDeleteVertexArrays(1, &lineVAO);
    glDeleteBuffers(1, &lineVBO);
}

void Renderer2D::DrawLine(const glm::vec2& a, const glm::vec2& b, const glm::vec3& color)
{
    
    float vertices[4] = {
       a.x, a.y,
       b.x, b.y
    };

    lineShader.Use();
    lineShader.SetUniform("uColor", color);

    glBindVertexArray(lineVAO);

    glBindBuffer(GL_ARRAY_BUFFER, lineVBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    glDrawArrays(GL_LINES, 0, 2);
}

void Renderer2D::DrawCoordinateAxis(float axisLength)
{
    const glm::vec3 axisColor = { 1.0f, 1.0f, 1.0f }; // 白色
    const glm::vec3 tickColor = { 0.8f, 0.8f, 0.8f }; // 灰色

    float half = axisLength;

    // ----------------------------
    // 1. 绘制 X 轴
    // ----------------------------
    DrawLine(
        glm::vec2(-half, 0),
        glm::vec2(half, 0),
        axisColor
    );

    // 绘制 X 轴刻度
    for (float x = -half; x <= half; x += tickInterval)
    {
        DrawLine(
            glm::vec2(x, -tickSize),
            glm::vec2(x, tickSize),
            tickColor
        );
    }

    // ----------------------------
    // 2. 绘制 Y 轴
    // ----------------------------
    DrawLine(
        glm::vec2(0, -half),
        glm::vec2(0, half),
        axisColor
    );

    // 绘制 Y 轴刻度
    for (float y = -half; y <= half; y += tickInterval)
    {
        DrawLine(
            glm::vec2(-tickSize, y),
            glm::vec2(tickSize, y),
            tickColor
        );
    }
}