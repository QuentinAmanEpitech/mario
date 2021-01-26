#include <SDL2/SDL.h>
#include "map.h"

void updateMap(SDL_Renderer *renderer, char defaultMap[22][LEVEL_MAX_LENGTH])
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < strlen(defaultMap[i]); j++)
        {
            if (defaultMap[i][j] == '1')
            {
                SDL_Log("%c", defaultMap[i][j]);
                SDL_Rect rect;
                rect.h = 32;
                rect.w = 32;
                rect.x = j * 32;
                rect.y = i * 32;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
    SDL_RenderPresent(renderer);
}

int parseMap(char level, char defaultMap[22][LEVEL_MAX_LENGTH])
{
    FILE *levelMap = NULL;
    //Allow 999 levels in the game
    char pathToLevel[15];
    sprintf(pathToLevel, "levels/%d.txt", level);
    levelMap = fopen(pathToLevel, "r");

    if (!levelMap)
        return -1;

    char stepLevel[LEVEL_MAX_LENGTH];
    int step = 0;

    while (fgets(stepLevel, LEVEL_MAX_LENGTH, levelMap) != NULL)
    {
        if (stepLevel[strlen(stepLevel) - 1] == '\n')
            stepLevel[strlen(stepLevel) - 1] = '\0';
        strcpy(defaultMap[step], stepLevel);

        step++;
    }

    fclose(levelMap);
    return 1;
}