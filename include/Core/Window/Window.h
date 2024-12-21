#pragma once
#include "Core/Core.h"
#include "Core/Window/WindowConfig.h"

#include "Core/Render/Interface.h"
#include "Core/Render/Framebuffer.h"

class Window
{
public:
    Window();
    ~Window();

    // Internal controller
    void Init();
    void Run();
    
    // Outside caller
    inline static Window* GetInstance() { return WinInstance; }

private:
    static void KeyFunction(GLFWwindow* window, int key, int scancode, int action, int mods);
    glm::vec2 getRelMousePosition();

private:
    static Window* WinInstance;
    static WindowSpec WinSpec;

    bool isRunning = true;

    GLFWwindow* WinConsole;
    Interface GUI;
    Environment Env;
    Ref<Framebuffer> RenderBuffer;
    
    friend class Interface;
};