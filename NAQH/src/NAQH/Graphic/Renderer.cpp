#include "Renderer.h"
#include "Platform/OpenGL/OpenGL_Renderer.h"

namespace NAQH {
    Renderer* Renderer::Create(RendererSpecs specs) {
        switch (specs.api) {
        case API_OPENGL:
            return new OpenGL_Renderer(specs);
            break;
        case API_VULKAN:
            break;
        default:
            break;
        }

        return nullptr;
    }
}