#pragma once
#include "Core.h"
#include "Math/Math.h"
#include "Events/Input.h"

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