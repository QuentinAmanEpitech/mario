#ifndef DEF_PLAYER
#define DEF_PLAYER
#include "map.h"

typedef struct Player Player;

struct Player
{
    int x;
    int y;
    int acceleration;
};

void placePlayer(Player *player, char defaultMap[22][LEVEL_MAX_LENGTH]);
void movePlayer(char direction, Player *player);

#endif