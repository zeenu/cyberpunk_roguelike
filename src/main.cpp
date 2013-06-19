#include <curses.h>

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

        // Place character
        mvaddch(playerY, playerX, '@');
    }
    return endwin();
}
