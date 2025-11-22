#pragma once
#include "../glm/glm.hpp"
#include <glad/glad.h>
#include "Shader.h"
// Renderer类，作为渲染的接口，提供绘制坐标轴以及各种星球的功能
const float tickInterval = 1.0f;   // 每 1 unit 显示一个刻度
const float axisLength = 100.0f; // 画从 -100 到 +100 unit 的轴
const float tickSize = 0.02f;  // 刻度线长度（世界坐标）
class Renderer2D
{
public:
	Renderer2D();
	~Renderer2D();
	void DrawLine(const glm::vec2& a, const glm::vec2& b, const glm::vec3& color);
	// 后续这里会扩展更多的图形绘制，包括绘制椭圆轨道等等
	void DrawCoordinateAxis(float axisLength); 
private:
	Shader lineShader;
	unsigned int lineVAO, lineVBO;
};