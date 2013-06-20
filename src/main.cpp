#include <curses.h>
#include <vector>

#include "tile.h"
#include "entity.h"

char *map[]={
    "###############",
    "#      #      #",
    "#             #",
    "#      ### ####",
    "#### ###   #  #",
    "#          #  #",
    "#          #  #",
    "#             #",
    "#          #  #",
    "###############"
};

enum Keys
{
    ESC = 27,
};

int main(int argc, char* argv[])
{
    std::vector<Entity> entities;

    Entity player;
    player.x = 1;
    player.y = 1;
    player.character = '@';
    player.hp = 10;

    entities.push_back(player);
    
    int keyDown = 0;
    int playerX = 1, playerY = 1;

    while ((27 != (keyDown = getch())))
    {
        // Initialize curses
        keypad(initscr(), 1);
        curs_set(0);

        // Draw temp map
        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 15; x++)
            {
                mvaddch(y, x, map[y][x]);
            }
        }

        if (KEY_UP == keyDown && map[playerY-1][playerX] == ' ')
            playerY--;
        if (KEY_DOWN == keyDown && map[playerY+1][playerX] == ' ')
                    playerY++;
        if (KEY_LEFT == keyDown && map[playerY][playerX-1] == ' ')
                    playerX--;
        if (KEY_RIGHT == keyDown && map[playerY][playerX+1] == ' ')
                    playerX++;

        entities[0].x = playerX;
        entities[0].y = playerY;

        // Place entities
        for (std::vector<Entity>::iterator entity = entities.begin(); entity != entities.end(); entity++)
        {
            mvaddch(entity->y, entity->x, entity->character);
        }
    }
    return endwin();
}
