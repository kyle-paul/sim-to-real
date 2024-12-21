#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <imgui.h>
#include <memory>

#include "Core/Render/Framebuffer.h"
#include "Core/Render/Texture.h"

class Interface
{
public:
    Interface();
    ~Interface();

public:
    void Init(GLFWwindow *window);
    void Begin();
    void End();
    void Render();
    void Styling();

private:
    static glm::vec2 m_ViewportSize;
};