#include "Application.h"
#include "Graphic/Window.h"
#include "Events/Input.h"

#include <SDL2/SDL.h>

namespace NAQH {
    Application* Application::instance = nullptr;
    ApplicationSpecs Application::appSpecs;
    bool Application::isRunning = true;

    Application::Application(ApplicationSpecs appSpecs) {
        this->appSpecs = appSpecs;
        Window::Create(appSpecs.title, appSpecs.width, appSpecs.height);
        Input::Create();
    }

    Application::~Application() {
        delete Window::instance;
        delete Input::instance;
        
        SDL_Quit();
    }

    void Application::Create(ApplicationSpecs appSpecs) {
        if(instance != nullptr) {
            return;
        }

        instance = new Application(appSpecs);
    }

    void Application::Run() {
        Start();

        while(isRunning) {
            Update();
        }
    }

    void Application::Start() {
        Window::Start();
        Input::Start();
    }

    void Application::Update() {
        Window::Update();
        Input::Update();
    }
}