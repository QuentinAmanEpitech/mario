#include "sprites.h"
#include <SDL2/SDL.h>
#include <dirent.h>
#include <string.h>

void loadSprites(Sprites *sprites, SDL_Renderer *renderer)
{
    SDL_Surface *sprite = SDL_LoadBMP("./assets/sky.bmp");
    sprites->sky = SDL_CreateTextureFromSurface(renderer, sprite);
    sprite = SDL_LoadBMP("./assets/brick.bmp");
    sprites->brick = SDL_CreateTextureFromSurface(renderer, sprite);
    sprite = SDL_LoadBMP("./assets/mario_right.bmp");
    sprites->player = SDL_CreateTextureFromSurface(renderer, sprite);
    sprite = SDL_LoadBMP("./assets/chance.bmp");
    sprites->chance = SDL_CreateTextureFromSurface(renderer, sprite);

    SDL_FreeSurface(sprite);
}