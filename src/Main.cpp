#include <stdlib.h>
#include <stdio.h>
#include "Core/Application.h"

int main() {
    NAQH::ApplicationSpecs specs;
    specs.title = "NAQH";
    specs.width = specs.height = 600;

    NAQH::Application::Create(specs);

    NAQH::Application::Run();

    return 0;
}