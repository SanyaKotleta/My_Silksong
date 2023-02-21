#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 25
#define LENGHT 81

typedef struct {
    int y;
    int x;
} object;

void gameplay(char map[][LENGHT], object player);

void grid(char map[][LENGHT]);
void control(object *player);
void output(char map[][LENGHT]);

int main() {
    object player = {18, 40};
    char map[HEIGHT][LENGHT];
    grid(map);
    map[player.y][player.x] = '@';
    gameplay(map, player);
    return 0;
}

void gameplay(char map[][LENGHT], object player) {
    initscr();
    noecho();
    FILE *f = freopen("/dev/tty", "r", stdin);
    while (player.x != 1911) {
        grid(map);
        map[player.y][player.x] = '@';
        output(map);
        control(&player);
    }
    endwin();
    fclose(f);
}

void grid(char map[][LENGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < LENGHT; j++) {
            if (i > 18)
                map[i][j] = '#';
            else
                map[i][j] = '-';
        }
    }
}

void control(object *player) {
    char control = 0;
    control = getch();
    if (control == 'a') player->x -= 1;
    if (control == 'd') player->x += 1;
    if (control == ']') player->x = 1911;
}

void output(char map[][LENGHT]) {
    erase();
    for (int i = 0; i < 2 * LENGHT + 1; i++) printw("%%");
    printw("\n");
    for (int i = 0; i < HEIGHT; i++) {
        printw("%%");
        for (int j = 0; j < LENGHT; j++) {
            if (j != LENGHT - 1)
                printw("%c ", map[i][j]);
            else
                printw("%c", map[i][j]);
        }
        printw("%%");
        if (HEIGHT != 0) printw("\n");
    }
    for (int i = 0; i < 2 * LENGHT + 1; i++) printw("%%");
}