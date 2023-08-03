#include "Window.h"

#ifdef NQ_PLATFORM_WINDOWS
    #include <Platform/GLFW/GLFW_Window.h>
#endif

namespace NAQH {
    Window* Window::Create(WindowSpecs specs) {
        #ifdef NQ_PLATFORM_WINDOWS
            return new GLFW_Window(specs);
        #else
            #error "Unsupported system"
        #endif
    }
}