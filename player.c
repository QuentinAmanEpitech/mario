#include "map.h"

void placePlayer(Player *player, char defaultMap[22][LEVEL_MAX_LENGTH])
{
    player->acceleration = 0;

    int hasFoundPosition = 0, column = 1;

    while (hasFoundPosition == 0)
    {
        for (int i = 21; i >= 0; i--)
        {
            if (defaultMap[i][column] == '0')
            {
                hasFoundPosition = 1;
                player->x = column * CELLSIZE;
                player->y = i * CELLSIZE;
                break;
            }
        }

        if (hasFoundPosition == 0)
            column++;
    }
}

void movePlayer(char direction, Player *player)
{
    switch (direction)
    {
    case 'd':
        player->x += 10;
        break;
    case 's':
        player->y += 10;
        break;
    case 'q':
        player->x -= 10;
        break;
    case 'z':
        player->y -= 10;
        break;
    }
}