#include <stdio.h>
#include <stdlib.h>

#define STR_STD_LENGTH 25

void * allocateArray(int size);
int countCharacters(char *str);
char * mixSentences(char *str1, char *str2);

int main(void) {
    char str1[STR_STD_LENGTH] = "Em de espeto de";
    char str2[STR_STD_LENGTH] = "casa ferreiro é pau";
    char *result;

    result = mixSentences(str1, str2);

    printf("%s", result);

    free(result);

    return 0;
}

void * allocateArray(int size) {
    void *a;

    a = malloc(size);

    if (a == NULL) {
        printf("Erro ao alocar memória.");
    }

    return a;
}

int countCharacters(char *str) {
    int count = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}

char * mixSentences(char *str1, char *str2) {
    int str1Length = countCharacters(str1);
    int str2Length = countCharacters(str2);
    char *result;
    int str1Index = 0;
    int str2Index = 0;
    int strSwitch = 0;
    int hasEnded = 0;
    int i;

    result = (char*) allocateArray((str1Length + str2Length) * sizeof(char));

    i = 0;
    while (!hasEnded) {

        if (!strSwitch) {
            if (str1[str1Index] == '\0' || str1[str1Index] == ' ') {
                strSwitch = 1;
                result[i] = ' ';
            } else {
                result[i] = str1[str1Index];
            }
            str1Index++;
        } else {
            if (str2[str2Index] == '\0' || str2[str2Index] == ' ') {
                strSwitch = 0;
                result[i] = ' ';
            } else {
                result[i] = str2[str2Index];
            }
            str2Index++;
        }

        i++;
        if (str1[str1Index] == '\0' && str2[str2Index] == '\0') {
            result[i] = '\0';
            hasEnded = 1;
        }
    }

    return result;

}
