#include <stdio.h>

void converteHora(int totalSegundos, int *hora, int *min, int *seg);
void printHour(int *hour, int *min, int *sec);
void captureInput(int *input);

int main(void) {
    int totalSeconds, hour, min, sec;

    captureInput(&totalSeconds);

    converteHora(totalSeconds, &hour, &min, &sec);

    printHour(&hour, &min, &sec);

    return 0;
}

void converteHora(int totalSegundos, int *hora, int *min, int *seg) {
    *hora  = totalSegundos / (60 * 60);
    *min  = (totalSegundos / 60) % 60;
    totalSegundos -= ((*hora * 60 * 60) + (*min * 60));
    *seg  = totalSegundos % (60 * 60);

}

void printHour(int *hour, int *min, int *sec) {
    printf("%02d:%02d:%02d", *hour, *min, *sec);
}

void captureInput(int *input) {
    printf("Por favor, insira a quantidade de segundos que deseja converter: ");
    scanf("%d", input);

    while (*input < 0) {
        printf("O valor de entrada não pode ser menor que zero. Tente novamente: ");
        scanf("%d", input);
    }
}
