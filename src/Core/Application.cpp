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

        while(running)
        {
            while(SDL_PollEvent(&event))
            {
                if(event.type == SDL_QUIT)
                    running = false;

                if(event.type == SDL_KEYDOWN)
                {
                    if(event.key.keysym.scancode == SDL_SCANCODE_LEFT)
                        rect.x -= 2;
                    if(event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                        rect.x += 2;
                    if(event.key.keysym.scancode == SDL_SCANCODE_UP)
                        rect.y -= 2;
                    if(event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                        rect.y += 2;
                }
            }

            SDL_SetRenderDrawColor(renderer, 17.85, 33.15, 43.35, 255);
            SDL_RenderClear(renderer);
            SDL_Texture* img = IMG_LoadTexture(renderer, "res/ScreenShot/screenshot.bmp");
            SDL_RenderCopyF(renderer, img, NULL, &rect);
            SDL_RenderPresent(renderer);
        }

        SDL_Quit();
    }
}