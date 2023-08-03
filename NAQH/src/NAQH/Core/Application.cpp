#include "Application.h"
#include "Window.h"
#include "NAQH/Graphic/Renderer.h"

namespace NAQH {
    Application::Application(ApplicationSpecs specs) {
        running = true;

        WindowSpecs windowSpecs = { specs.windowTitle, specs.width, specs.height };
        window = (void*)Window::Create(windowSpecs);

        RendererSpecs rendererSpecs = { specs.api, (Window*)window };
        renderer = (void*)Renderer::Create(rendererSpecs);
    }

    Application::~Application() {
        Close();
    }

    void Application::Run() {
        Start();

        while (running) {
            Update();
        }
    }

    void Application::Start() {
        Window* wnd = (Window*)window;
        wnd->Start();

        Renderer* rnder = (Renderer*)renderer;
        rnder->Start();
    }

    void Application::Update() {
        Window* wnd = (Window*)window;
        wnd->Update();

        if (wnd->Closed()) {
            running = false;
        }

        Renderer* rnder = (Renderer*)renderer;
        rnder->Update();
    }

    void Application::Close() {
        delete renderer;
        delete window;
    }
}