#ifndef _NQ_GLFW_WINDOW_H_
#define _NQ_GLFW_WINDOW_H_
#include "NAQH/Core/Core.h"
#include "NAQH/Core/Window.h"
#include <glfw/glfw3.h>

namespace NAQH {
    class GLFW_Window : public Window {
    public:
        GLFW_Window(WindowSpecs specs);
        ~GLFW_Window();

        void Start() override;
        void Update() override;
        void Close() override;

        uint16_t GetWidth() override;
        uint16_t GetHeight() override;
        bool Closed() override;
    private:
        GLFWwindow* window;
    };
}

#endif