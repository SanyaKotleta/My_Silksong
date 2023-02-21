#include <stdio.h>

#define HEIGHT 25
#define LENGHT 81

typedef struct {
    int y;
    int x;
} object;

void grid(char map[][LENGHT]);
void transcript(char map[][LENGHT]);
void output(char map[][LENGHT]);
void transcript_output(char map[][LENGHT]);

int main() {
    object player = {18, 40};
    char map[HEIGHT][LENGHT];
    grid(map);
    map[player.y][player.x] = '@';
    // output(map);
    // printf("\n");
    // transcript_output(map);
    // output(map);
    // printf("\n");
    // transcript(map);
    output(map);
}

void grid(char map[][LENGHT]) {
    // Генерируем карту из нулей
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < LENGHT; j++) {
            if (i > 18)
                map[i][j] = '#';
            else
                map[i][j] = '-';
        }
    }
}

void transcript(char map[][LENGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < LENGHT; j++) {
            if (map[i][j] == '0') map[i][j] = '-';
            if (map[i][j] == '1') map[i][j] = '#';
        }
    }
}

void output(char map[][LENGHT]) {
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

void transcript_output(char map[][LENGHT]) {
    for (int i = 0; i < LENGHT + 2; i++) printf("%%");
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        printf("%%");
        for (int j = 0; j < LENGHT; j++) {
            if (j != LENGHT - 1) {
                if (map[i][j] == '0') printf("-");
                if (map[i][j] == '1') printf("#");
            } else {
                if (map[i][j] == '0') printf("-");
                if (map[i][j] == '1') printf("#");
            }
        }
        printf("%%");
        if (HEIGHT != 0) printf("\n");
    }
    for (int i = 0; i < LENGHT + 2; i++) printf("%%");
}