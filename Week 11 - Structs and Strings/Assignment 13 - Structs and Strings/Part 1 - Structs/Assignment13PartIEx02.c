#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 45
#define PERSON_AMOUNT 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int birthday;
    int birthMonth;
} Person;

Person * allocatePersonArray(int size);
void captureBirthday(int *bDay, int *bMonth);
void captureMonth(int *bMonth);
Person * createPersonArray(int size);
void fillPersonInfo(Person *p);
char * getMonth(int n);
void printMonthlyBirthdays(Person *p, int amount);

int main(void) {
    Person *personList;

    personList = createPersonArray(PERSON_AMOUNT);

    printMonthlyBirthdays(personList, PERSON_AMOUNT);

    return 0;
}

Person * allocatePersonArray(int size) {
    Person *p;

    p = (Person*) malloc(size * sizeof(Person));

    if (p == NULL) {
        printf("Erro ao alocar memória.");
    }

    return p;
}

void captureBirthday(int *bDay, int *bMonth) {
    int maxDay;

    if (*bMonth == 2) {
        maxDay = 28;
    } else if (*bMonth == 4 || *bMonth == 6 || *bMonth == 9 || *bMonth == 11) {
        maxDay = 30;
    } else {
        maxDay = 31;
    }

    printf("Por favor, insira o dia do aniversário: ");
    scanf("%d", bDay);

    while (*bDay < 1 || *bDay > maxDay) {
        printf("Dia inválido para o mês de %s! Por favor, tente novamente: ", getMonth(*bMonth));
        scanf("%d", bDay);
    }
}

void captureMonth(int *bMonth) {
    printf("Por favor, insira o mês do aniversário: ");
    scanf("%d", bMonth);

    while (*bMonth < 1 || *bMonth > 12) {
        printf("Mês inválido! Por favor, tente novamente: ");
        scanf("%d", bMonth);
    }
}

Person * createPersonArray(int size) {
    Person *p;
    int i;

    p = allocatePersonArray(size);

    for (i = 0; i < size; i++) {
        fillPersonInfo(&p[i]);
    }

    return p;
}

void fillPersonInfo(Person *p) {
    printf("Pro favor, insira o nome: ");
    fgets(p->name, MAX_NAME_LENGTH, stdin);
    p->name[strcspn(p->name, "\n")] = 0; // Removing the \n character at the end of the field captured by thefgets function.
    captureMonth(&p->birthMonth);
    captureBirthday(&p->birthday, &p->birthMonth);
    getchar(); // Removing the linebreak character from the input buffer.
}

char * getMonth(int n) {
    char *month;
    switch (n) {
        case 1:
            month = "Janeiro";
            break;

        case 2:
            month = "Fevereiro";
            break;

        case 3:
            month = "Março";
            break;

        case 4:
            month = "Abril";
            break;

        case 5:
            month = "Maio";
            break;

        case 6:
            month = "Junho";
            break;

        case 7:
            month = "Julho";
            break;

        case 8:
            month = "Agosto";
            break;

        case 9:
            month = "Setembro";
            break;

        case 10:
            month = "Outubro";
            break;

        case 11:
            month = "Novembro";
            break;

        case 12:
            month = "Dezembro";
            break;
        default:
            month = "ERROR";
            printf("Erro: Mês fora do limite!");
            break;
    }

    return month;
}

void printMonthlyBirthdays(Person *p, int amount) {
    int i, j;
    int count = 0;

    printf("Aniversariantes:\n");
    for (i = 1; i < 12; i++) {
        printf("%s: ", getMonth(i));

        count = 0;
        for (j = 0; j < amount; j++) {
            if (p[j].birthMonth == i) {
                printf("%s ", p[j].name);
                count++;
            }
        }
        if (count == 0) {
            printf("Sem aniversariantes.");
        }
        printf(";\n");
    }
}
