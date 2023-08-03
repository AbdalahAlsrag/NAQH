#ifndef _NQ_WINDOW_H_
#define _NQ_WINDOW_H_
#include "Core.h"

namespace NAQH {
    struct WindowSpecs {
        char* title;
        uint16_t width;
        uint16_t height;
    };

    class Window {
    public:
        virtual ~Window() = default;
        
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void Close() = 0;

        virtual uint16_t GetWidth() = 0;
        virtual uint16_t GetHeight() = 0;
        virtual bool Closed() = 0;

        static Window* Create(WindowSpecs specs);
    private:
    };
}

#endif