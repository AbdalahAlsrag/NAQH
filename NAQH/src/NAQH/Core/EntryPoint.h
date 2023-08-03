#include "NAQH/Core/Core.h"
#include "Application.h"

using namespace NAQH;

int main() {
    Application* app = CreateApplication();
    
    app->Run();

    delete app;
    return 0;
}