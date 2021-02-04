#include <SDL2/SDL.h>
#include "map.h"

void updateMap(SDL_Renderer *renderer, char defaultMap[22][LEVEL_MAX_LENGTH], Player player, Sprites sprites)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_Rect rect;

    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < strlen(defaultMap[i]); j++)
        {
            rect.h = 32;
            rect.w = 32;
            rect.x = j * 32;
            rect.y = i * 32;

            switch (defaultMap[i][j])
            {
            case '0':
                SDL_RenderCopy(renderer, sprites.sky, NULL, &rect);
                break;
            case '1':
                SDL_RenderCopy(renderer, sprites.brick, NULL, &rect);
                break;
            case '2':
                SDL_RenderCopy(renderer, sprites.chance, NULL, &rect);
                break;
            default:
                break;
            }
        }
    }

    rect.x = player.x;
    rect.y = player.y;

    SDL_RenderCopy(renderer, sprites.player, NULL, &rect);

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