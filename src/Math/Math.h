#pragma once

namespace NAQH{ namespace Math{
    class Vector2
    {
    public:
        Vector2(float p_x, float p_y)
        : x(p_x), y(p_y)
        {}

        Vector2()
        {}

        float x, y;
    private:
    };
}}