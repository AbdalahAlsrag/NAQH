#ifndef _NQ_RENDERER_H_
#define _NQ_RENDERER_H_
#include "NAQH/Core/Core.h"
#include "NAQH/Core/Window.h"
#include "RendererApi.h"
#include "Color.h"

namespace NAQH {
    struct RendererSpecs {
        RendererApi api;
        Window* window;
    };

    class Renderer {
    public:
        virtual ~Renderer() = default;

        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void Close() = 0;

        virtual void SetClearColor(Color color) = 0;

        static Renderer* Create(RendererSpecs specs);
    private:
    };
}

#endif