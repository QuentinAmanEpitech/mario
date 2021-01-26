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
                player->x = column;
                player->y = i;
                break;
            }
        }

        if (hasFoundPosition == 0)
            column++;
    }
}