#ifndef _NQ_APPLICATION_H_
#define _NQ_APPLICATION_H_

#include "NAQH/Core/Core.h"
#include "NAQH/Graphic/RendererApi.h"

namespace NAQH {
    struct ApplicationSpecs {
        char* windowTitle;
        uint16_t width;
        uint16_t height;
        RendererApi api;
    };

    class Application {
    public:
        Application(ApplicationSpecs specs);
        ~Application();

        void Run();

        bool running;
    private:
        void Start();
        void Update();
        void Close();

        void* window;
        void* renderer;
    };

}

NAQH::Application* CreateApplication();

#endif