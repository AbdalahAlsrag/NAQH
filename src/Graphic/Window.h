#pragma once

namespace NAQH {
    class Window {
    public:

    private:
        Window(const char* title, int width, int height);
        ~Window();
        
        static void Create(const char* title, int width, int height);

        static void Start();
        static void Update();

        static void SwapBuffers();
        static void Destroy();

        static Window* instance;

        static int* window;

        friend class Application;
    };
}