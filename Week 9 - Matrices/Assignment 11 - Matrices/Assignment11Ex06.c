#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

void fillBingoCard(int dim, int bc[dim][dim]);
int verifyNumbersInBingoCard(int number, int currentPosX, int currentPosY, int bc[currentPosX][currentPosY]);
void printBingoCard(int dim, int bc[dim][dim]);

int main(void) {
    srand(time(NULL));
    int bingoCard[DIM][DIM];
    int dim = DIM;

    fillBingoCard(dim, bingoCard);

    printf("Cartela:\n\n");
    printBingoCard(dim, bingoCard);

    return 0;
}

void fillBingoCard(int dim, int bc[dim][dim]) {
    int i, j;
    int randomNumber;

    for (i = 0; i < dim; i++) {
        j = 0;
        while (j < dim) {
            randomNumber = rand() % 100;

            if (verifyNumbersInBingoCard(randomNumber, i, j, bc)) {
                bc[i][j] = randomNumber;
                j++;
            }
        }
    }
}

int verifyNumbersInBingoCard(int number, int currentPosX, int currentPosY, int bc[currentPosX][currentPosY]) {
    int i, j;

    for (i = 0; i < currentPosX; i++) {
        for (j = 0; j < currentPosY; j++) {
            if (bc[i][j] == number) {
                return 0;
            }
        }
    }
    return 1;
}

void printBingoCard(int dim, int bc[dim][dim]) {
    int i, j;

    printf("B\tI\tN\tG\tO\n\n");
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("%d\t", bc[i][j]);
        }
        printf("\n");
    }
}
