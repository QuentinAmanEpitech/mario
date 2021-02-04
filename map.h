#ifndef DEF_MAP
#define DEF_MAP
#define LEVEL_MAX_LENGTH 1000
#include <SDL2/SDL.h>
#include "game.h"
#include "player.h"
#include "sprites.h"

typedef struct Map Map;

struct Map
{
    char defaultMap[22][LEVEL_MAX_LENGTH];
};

void updateMap(SDL_Renderer *renderer, char defaultMap[22][LEVEL_MAX_LENGTH], Player player, Sprites sprite);
int parseMap(char level, char defaultMap[22][LEVEL_MAX_LENGTH]);

#endif