#include <NAQH.h>

using namespace NAQH;

Application* CreateApplication() {
    ApplicationSpecs specs = { "NAQH", 500, 500, API_OPENGL };

    Application* app = new Application(specs);

    return app;
}