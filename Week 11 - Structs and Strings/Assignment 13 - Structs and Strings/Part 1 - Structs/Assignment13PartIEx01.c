#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int horas;
    int minutos;
    int segundos;
} Tempo;

Tempo convertToHoursMinutesSeconds(int s);

int main(void) {
    int testValue = 86300;
    Tempo convertedTime;

    convertedTime = convertToHoursMinutesSeconds(testValue);

    printf("%02d:%02d:%02d", convertedTime.horas, convertedTime.minutos, convertedTime.segundos);

    return 0;
}

Tempo convertToHoursMinutesSeconds(int s) {
    Tempo t;

    t.horas = s / 60 / 60;
    t.minutos = s / 60 % 60;
    t.segundos = s % 60;

    return t;

}
