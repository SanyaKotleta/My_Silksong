#include <stdio.h>

#define HEIGHT 25
#define LENGHT 80

void grid(char map[][LENGHT]);
void matrix_output(char map[][LENGHT]);
void transcript_output(char map[][LENGHT]);

int main() {
    char map[HEIGHT][LENGHT];
    grid(map);
    matrix_output(map);
    printf("\n");
    transcript_output(map);
}

void grid(char map[][LENGHT]) {
    // Генерируем карту из нулей
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < LENGHT; j++) {
            if (i > 18)
                map[i][j] = '1';
            else
                map[i][j] = '0';
        }
    }
}

void matrix_output(char map[][LENGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < LENGHT; j++) {
            if (j != LENGHT - 1)
                printf("%c ", map[i][j]);
            else
                printf("%c", map[i][j]);
        }
        if (HEIGHT != 0) printf("\n");
    }
}

void transcript_output(char map[][LENGHT]) {
    for (int i = 0; i < LENGHT + 1; i++) printf("%%");
    for (int i = 0; i < HEIGHT; i++) {
        printf("%%");
        for (int j = 0; j < LENGHT; j++) {
            if (j != LENGHT - 1) {
                if (map[i][j] == '0') printf(" ");
                if (map[i][j] == '1') printf("#");
            }
            else {
                if (map[i][j] == '0') printf(" ");
                if (map[i][j] == '1') printf("#");
            }
        }
        printf("%%");
        if (HEIGHT != 0) printf("\n");
    }
    for (int i = 0; i < LENGHT + 2; i++) printf("%%");
}