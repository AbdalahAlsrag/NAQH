#ifndef _NQ_COLOR_H_
#define _NQ_COLOR_H_
#include "NAQH/Core/Core.h"

struct Color {
    inline float RToFLOAT() {
        return (float)r / 255;
    }

    inline float GToFLOAT() {
        return (float)g / 255;
    }

    inline float BToFLOAT() {
        return (float)b / 255;
    }

    inline float AToFLOAT() {
        return (float)a / 255;
    }

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

static const Color
GREY = { 192, 192, 192, 255 }, DARK_GREY = { 128, 128, 128, 255 }, VERY_DARK_GREY = { 64, 64, 64, 255 },
RED = { 255, 0, 0, 255 }, DARK_RED = { 128, 0, 0, 255 }, VERY_DARK_RED = { 64, 0, 0, 255 },
YELLOW = { 255, 255, 0, 255 }, DARK_YELLOW = { 128, 128, 0, 255 }, VERY_DARK_YELLOW = { 64, 64, 0, 255 },
GREEN = { 0, 255, 0, 255 }, DARK_GREEN = { 0, 128, 0, 255 }, VERY_DARK_GREEN = { 0, 64, 0, 255 },
CYAN = { 0, 255, 255, 255 }, DARK_CYAN = { 0, 128, 128, 255 }, VERY_DARK_CYAN = { 0, 64, 64, 255 },
BLUE = { 0, 0, 255, 255 }, DARK_BLUE = { 0, 0, 128, 255 }, VERY_DARK_BLUE = { 0, 0, 64, 255 },
MAGENTA = { 255, 0, 255, 255 }, DARK_MAGENTA = { 128, 0, 128, 255 }, VERY_DARK_MAGENTA = { 64, 0, 64, 255 },
WHITE = { 255, 255, 255, 255 }, BLACK = { 0, 0, 0, 255 }, BLANK = { 0, 0, 0, 0 };

#endif