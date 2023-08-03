#ifndef _NQ_OPENGL_RENDERER_H_
#define _NQ_OPENGL_RENDERER_H_
#include "NAQH/Core/Core.h"
#include "NAQH/Core/Window.h"
#include "NAQH/Graphic/Renderer.h"
#include "NAQH/Graphic/Color.h"

namespace NAQH {
    class OpenGL_Renderer : public Renderer {
    public:
        OpenGL_Renderer(RendererSpecs specs);
        ~OpenGL_Renderer();


        void Start() override;
        void Update() override;
        void Close() override;

        void SetClearColor(Color color) override;
    private:
        Window* window;
        Color clearColor;
    };
}

#endif