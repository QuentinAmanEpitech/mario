#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "game.h"
#include "map.h"
#include "player.h"

int main(int argc, char const *argv[])
{
    Map map;
    if (parseMap(1, map.defaultMap) == -1)
        goto Quit;

    Player player;

    placePlayer(&player, map.defaultMap);

    if (initSDL() == -1)
        goto Quit;

    SDL_Event event;

    SDL_Window *pWindow = generateWindow("Mario");
    if (!pWindow)
        goto Quit;

    SDL_Renderer *pRenderer = generateRenderer(pWindow);
    if (!pRenderer)
        goto Quit;

    int playGame = 1;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;
    double refreshRate = 0;

    while (playGame == 1)
    {
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                playGame = 0;
                break;
            case SDL_KEYDOWN:
                movePlayer(event.key.keysym.sym, &player);
                break;
            }
        }
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        refreshRate += (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

        if (refreshRate >= (1000 / 16))
        {
            updateMap(pRenderer, map.defaultMap, player);
            refreshRate = 0;
        }
    }

Quit:
    if (!pRenderer)
        SDL_DestroyRenderer(pRenderer);
    if (!pWindow)
        SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return EXIT_SUCCESS;
}