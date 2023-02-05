#pragma once
#include "Core.h"

namespace NAQH{
    class NQ_API Application
    {
    public:
        Application();
        ~Application();
        void Run();
    private:
    };

    Application* CreateApplication();
}