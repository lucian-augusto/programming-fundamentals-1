#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6

void fillBoard(int size, int b[size][size]);
void fillFirstLineAndColumn(int size, int b[size][size]);
void printBoard(int size, int b[size][size]);

int main(void) {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE];
    int size = BOARD_SIZE;

    fillFirstLineAndColumn(size, board);

    fillBoard(size, board);

    printBoard(size, board);
    return 0;
}

void fillBoard(int size, int b[size][size]) {
    int i, j;
    int neighborhoodSum = 0;

    for (i = 1; i < size; i++) {
        for (j = 1; j < size; j++) {
            neighborhoodSum = b[i-1][j] + b[i-1][j-1] + b[i][j-1];

            if (neighborhoodSum >= 2) {
                b[i][j] = 0;
            } else {
                b[i][j] = 1;
            }
            neighborhoodSum = 0;
        }
    }
}

void fillFirstLineAndColumn(int size, int b[size][size]) {
    int i;

    for (i = 0; i < size; i++) {
        b[i][0] = rand() % 2;
        b[0][i] = rand() % 2;
    }
}

void printBoard(int size, int b[size][size]) {
     int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}
