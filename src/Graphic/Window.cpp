#include "Window.h"

#include <SDL2/SDL.h>

namespace NAQH {
    Window* Window::instance = nullptr;
    int* Window::window = nullptr;
    
    Window::Window(const char* title, int width, int height) {
        Window::window = (int*)SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    }

    Window::~Window() {
        Destroy();
    }

    void Window::Create(const char* title, int width, int height) {
        if(instance != nullptr) {
            return;
        }

        instance = new Window(title, width, height);
    }

    void Window::Destroy() {
        SDL_DestroyWindow((SDL_Window*)window);
    }

    void Window::Start() {

    }

    void Window::Update() {

    }

    void Window::SwapBuffers() {
        
    }
}