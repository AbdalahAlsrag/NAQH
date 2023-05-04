#pragma once

namespace NAQH {
    struct ApplicationSpecs {
        int width, height;
        const char* title;
    };

    class Application {
    public:
        ~Application();

        static void Create(ApplicationSpecs appSpecs);
        static void Run();
    private:
        Application(ApplicationSpecs appSpecs);

        static void Start();
        static void Update();

        static Application* instance;

        static ApplicationSpecs appSpecs;
        static bool isRunning;
    };
}