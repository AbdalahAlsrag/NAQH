#include "OpenGL_Renderer.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace NAQH {
    OpenGL_Renderer::OpenGL_Renderer(RendererSpecs specs) {
        clearColor = WHITE;
        window = specs.window;

        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    }

    OpenGL_Renderer::~OpenGL_Renderer() {
        Close();
    }

    void OpenGL_Renderer::Start() {
        glViewport(0, 0, window->GetWidth(), window->GetHeight());
    }

    void OpenGL_Renderer::Update() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(clearColor.RToFLOAT(), clearColor.GToFLOAT(), clearColor.BToFLOAT(), clearColor.AToFLOAT());
    }

    void OpenGL_Renderer::Close() {
        
    }

    void OpenGL_Renderer::SetClearColor(Color color) {
        clearColor = color;
    }
}