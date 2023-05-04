#pragma once

namespace NAQH {
    class Input
    {
    public:
        static bool KeyPressed();
        static bool KeyDown();
        static bool KeyUp();

        static bool ButtonPressed();
        static bool ButtonDown();
        static bool ButtonUp();
    private:
        Input();
        ~Input();

        static void Create();

        static void Start();
        static void Update();

        static Input* instance;

        friend class Application;
    };
}