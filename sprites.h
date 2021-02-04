#ifndef DEF_SPRITES
#define DEF_SPRITES
#include <SDL2/SDL.h>

typedef struct Sprites Sprites;

struct Sprites
{
    SDL_Texture *sky;
    SDL_Texture *brick;
    SDL_Texture *player;
    SDL_Texture *chance;
};

void loadSprites(Sprites *sprites, SDL_Renderer *renderer);

#endif