#include "game.h"
#include <SDL2/SDL.h>

int initSDL()
{
    return SDL_Init(SDL_INIT_VIDEO);
}

SDL_Window *generateWindow(char name[])
{
    return SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
}

SDL_Renderer *generateRenderer(SDL_Window *window)
{
    return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}