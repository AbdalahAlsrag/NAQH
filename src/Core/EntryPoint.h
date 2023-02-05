#pragma once

#include "Application.h"

#ifdef NQ_System_Windows

extern NAQH::Application* NAQH::CreateApplication();

int main(int argc, char** argv)
{
    NAQH::Application* app = NAQH::CreateApplication();
    app->Run();
    delete app;
}

#endif