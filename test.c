#include <curses.h>
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
    while (player.x != 1911) {
        grid(map);
        map[player.y][player.x] = '@';
        control(&player);
        output(map);
        printf("\n");
    }
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
    control = getchar();
    if (control == 'a') player->x -= 1;
    if (control == 'd') player->x += 1;
    if (control == ']') player->x = 1911;
}

void output(char map[][LENGHT]) {
    for (int i = 0; i < 100; i++) printf("\n");
    for (int i = 0; i < 2 * LENGHT + 1; i++) printf("%%");
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        printf("%%");
        for (int j = 0; j < LENGHT; j++) {
            if (j != LENGHT - 1)
                printf("%c ", map[i][j]);
            else
                printf("%c", map[i][j]);
        }
        printf("%%");
        if (HEIGHT != 0) printf("\n");
    }
    for (int i = 0; i < 2 * LENGHT + 1; i++) printf("%%");
}