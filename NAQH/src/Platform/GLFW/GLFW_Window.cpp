#include "GLFW_Window.h"

namespace NAQH {
    GLFW_Window::GLFW_Window(WindowSpecs specs) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(specs.width, specs.height, specs.title, NULL, NULL);
        glfwMakeContextCurrent(window);
    }

    GLFW_Window::~GLFW_Window() {
        Close();
    }

    void GLFW_Window::Start() {

    }

    void GLFW_Window::Update() {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    void GLFW_Window::Close() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    uint16_t GLFW_Window::GetWidth() {
        int width = 0;
        glfwGetWindowSize(window, &width, NULL);

        return width;
    }

    uint16_t GLFW_Window::GetHeight() {
        int height = 0;
        glfwGetWindowSize(window, NULL, &height);

        return height;
    }

    bool GLFW_Window::Closed() {
        return glfwWindowShouldClose(window);
    }
}