#include "Input.h"

#include <SDL2/SDL.h>

using namespace NAQH::Math;

namespace NAQH{ namespace Events{
    Input::Input()
    {
        SDL_Init(SDL_INIT_GAMECONTROLLER);
        keyboardState = SDL_GetKeyboardState(&keyLength);
        prevKeyboardState = new Uint8[keyLength];
        memcpy(prevKeyboardState, keyboardState, keyLength);
    }

    bool Input::KeyDown(Keys p_scanCode)
    {
        return keyboardState[p_scanCode];
    }

    bool Input::KeyPressed(Keys p_scanCode)
    {
        return !prevKeyboardState[p_scanCode] && keyboardState[p_scanCode];
    }

    bool Input::KeyReleased(Keys p_scanCode)
    {
        return prevKeyboardState[p_scanCode] && !keyboardState[p_scanCode];
    }

    bool Input::MouseButtonDown(MouseButton p_button)
    {
        Uint32 mask;

        switch (p_button)
        {
            case left:
                mask = SDL_BUTTON_LMASK;
                break;
            case right:
                mask = SDL_BUTTON_RMASK;
                break;
            case middle:
                mask = SDL_BUTTON_MMASK;
                break;
            case back:
                mask = SDL_BUTTON_X1MASK;
                break;
            case forward:
                mask = SDL_BUTTON_X2MASK;
                break;
            default:
                mask = 0;
        }

        return (mouseState & mask);
    }

    bool Input::MouseButtonPressed(MouseButton p_button)
    {
        Uint32 mask;

        switch (p_button)
        {
            case left:
                mask = SDL_BUTTON_LMASK;
                break;
            case right:
                mask = SDL_BUTTON_RMASK;
                break;
            case middle:
                mask = SDL_BUTTON_MMASK;
                break;
            case back:
                mask = SDL_BUTTON_X1MASK;
                break;
            case forward:
                mask = SDL_BUTTON_X2MASK;
                break;
            default:
                mask = 0;
        }

        return !(prevMouseState & mask) && (mouseState & mask);
    }

    bool Input::MouseButtonReleased(MouseButton p_button)
    {
        Uint32 mask;

        switch (p_button)
        {
            case left:
                mask = SDL_BUTTON_LMASK;
                break;
            case right:
                mask = SDL_BUTTON_RMASK;
                break;
            case middle:
                mask = SDL_BUTTON_MMASK;
                break;
            case back:
                mask = SDL_BUTTON_X1MASK;
                break;
            case forward:
                mask = SDL_BUTTON_X2MASK;
                break;
            default:
                mask = 0;
        }

        return (prevMouseState & mask) && !(mouseState & mask);
    }

    Vector2 Input::MousePosition()
    {
        return Vector2((float)mouseX, (float)mouseY);
    }

    Vector2 Input::GlobalMousePosition()
    {
        return Vector2((float)globalMousex, (float)globalMouseY);
    }
        
    int GamePadNumber()
    {
        return SDL_NumJoysticks();
    }

    // bool GamePadButtonDown()
    // {

    // }

    // bool GamePadButtonPressed()
    // {

    // }

    // bool GamePadButtonReleased()
    // {

    // }

    // Vector2 LeftStickPosition()
    // {
        
    // }

    // Vector2 RightStickPosition()
    // {

    // }

    void Input::Update()
    {
        mouseState = SDL_GetMouseState(&mouseX, &mouseY);
        globalMouseState = SDL_GetGlobalMouseState(&globalMousex, &globalMouseY);
    }

    void Input::UpdatePrev()
    {
        memcpy(prevKeyboardState, keyboardState, keyLength);
        prevMouseState = mouseState;
        globalPrevMouseState = globalMouseState;
    }
}}