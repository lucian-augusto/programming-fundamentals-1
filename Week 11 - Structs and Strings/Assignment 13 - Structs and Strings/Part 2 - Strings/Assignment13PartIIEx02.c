#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 200

int countAppearances(char *word, char *sentence);

int main(void) {
    char sentence[MAX_LENGTH] = "ANA E MARIANA GOSTAM DE BANANA";
    char word[MAX_LENGTH] = "ANA";
    int appearances;

    appearances = countAppearances(word, sentence);

    printf("Na frase \"%s\", a palavra \"%s\" se repete %d vezes", sentence, word, appearances);
    return 0;
}
int countAppearances(char *word, char *sentence) {
    int i, j;
    int count = 0;
    int wordLength = strlen(word);
    int isAMatch = 1;

    for (i = 0; sentence[i] != '\0'; i++) {
        isAMatch = 1;
        for (j = 0; j < wordLength; j++) {
            if (sentence[i + j] != word[j]) {
                isAMatch = 0;
                break;
            }
        }

        if (isAMatch) {
            count++;
        }
    }

    return count;
}
