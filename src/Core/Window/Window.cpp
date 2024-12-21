#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core/Window/Window.h"

#include "Core/Debug/Assert.h"
#include "Core/Debug/Logging.h"

#include "imgui.h"

#include "Core/Render/Renderer.h"

Window *Window::WinInstance = nullptr;
WindowSpec Window::WinSpec;

Window::Window()
{
    ASSERT(!WinInstance, "Window already exits!");
    WinInstance = this;
}

Window::~Window()
{
    glfwDestroyWindow(WinConsole);
    glfwTerminate();
}

void Window::KeyFunction(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

glm::vec2 Window::getRelMousePosition()
{
    double x = 0, y = 0;
    glfwGetCursorPos(WinConsole, &x, &y);
    return { x, y };
}

void Window::Init()
{
    // Init window console
    if (!glfwInit())
    {
        ERROR("Could not initialize GLFW window!");
        exit(-1);
    }

    WinConsole = glfwCreateWindow(WinSpec.Width, WinSpec.Height, 
                                  WinSpec.Title.c_str(), NULL, NULL);
    if (!WinConsole)
    {
        glfwTerminate();
        ERROR("Creating GLFW window failed!");
        exit(-1);
    }
    glfwMakeContextCurrent(WinConsole);
    glfwSetKeyCallback(WinConsole, KeyFunction);

    // Init Render & Interface
    Renderer::Init();
    GUI.Init(WinConsole);

    // Init Frame Render Buffer
    FramebufferConfig fbspec;
    fbspec.Attachments = { FramebufferTextureFormat::RGBA8, 
                           FramebufferTextureFormat::RED_INTEGER, 
                           FramebufferTextureFormat::RED_INTEGER, 
                           FramebufferTextureFormat::Depth };
    fbspec.Width = 1200.0f;
	fbspec.Height = 810.0f;
	RenderBuffer = Framebuffer::Create(fbspec);
}


void Window::Run()
{
    while (!glfwWindowShouldClose(WinConsole))
    {        
        int display_w, display_h;
        glfwGetFramebufferSize(WinConsole, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        WinSpec.Aspect = (float)display_w / (float)display_h;
        Env.camera.CamSpec.Aspect = WinSpec.Aspect;

        // Render scene
        RenderBuffer->Bind();
        RenderBuffer->ClearAttachment(1, -1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(WinSpec.BgColor[0], WinSpec.BgColor[1], 
                     WinSpec.BgColor[2], WinSpec.BgColor[3]);

        // TODO: add scene
        RenderBuffer->Unbind();

        // Interface Render
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        GUI.Begin();
        GUI.Render();
        GUI.End();

        // Swap buffer
        glfwPollEvents();
        glfwSwapBuffers(WinConsole);
    }
}