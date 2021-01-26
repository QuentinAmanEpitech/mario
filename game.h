#ifndef DEF_GAME
#define DEF_GAME
#define WIDTH 1280
#define HEIGHT 704
#define CELLSIZE 32
#include <SDL2/SDL.h>

int initSDL();
SDL_Window *generateWindow(char name[]);
SDL_Renderer *generateRenderer(SDL_Window *window);

#endif