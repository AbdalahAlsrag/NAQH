#include "Application.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace NAQH{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        SDL_Init(SDL_INIT_VIDEO);
		SDL_Window* window = SDL_CreateWindow("ReNAQH", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetWindowResizable(window, SDL_TRUE);
        SDL_Event event;
        bool running = true;
        SDL_FRect rect = {100, 100, 200, 200};
        SDL_Texture* img = IMG_LoadTexture(renderer, "res/ScreenShot/screenshot.bmp");
        int x = 0, y = 0;
        NAQH::Events::Input input = NAQH::Events::Input(); 

        while(running)
        {
            input.Update();
            while(SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_QUIT:
                        running = false;
                        break;
                    default:
                        break;
                }
            }

            // if(input.KeyDown(input.Key_W))
            //     y -= 5;
            // if(input.KeyDown(input.Key_S))
            //     y += 5;
            // if(input.KeyDown(input.Key_D))
            //     x += 5;
            // if(input.KeyDown(input.Key_A))
            //     x -= 5;

            x = input.MousePosition().x;
            y = input.MousePosition().y;

            rect.x = x;
            rect.y = y;

            rect.x = x - rect.w/2;
            rect.y = y - rect.h/2;

            SDL_ShowCursor(false);

            SDL_SetRenderDrawColor(renderer, 17.85, 33.15, 43.35, 255);
            SDL_RenderClear(renderer);
            SDL_RenderCopyF(renderer, img, NULL, &rect);
            SDL_RenderPresent(renderer);
            input.UpdatePrev();
        }

        SDL_Quit();
    }
}