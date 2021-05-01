#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER 100

typedef struct {
    char name[BUFFER];
    char district[BUFFER];
    char password[BUFFER];
} Person;

void capturePersonData(Person *p);
void captureString(char *s);
void generateFirstPassword(char *name, char *district, char *password);
int isVowel(char c);

int main(void) {
    Person p;

    capturePersonData(&p);

    printf("A sua senha é: %s", p.password);
    
    return 0;
}

void capturePersonData(Person *p) {
    printf("Por favor, insira o seu nome: ");
    captureString(p->name);

    printf("Por favor, insira o bairro onde mora: ");
    captureString(p->district);
    
    generateFirstPassword(p->name, p->district, p->password);
}

void captureString(char *s) {
    fgets(s, BUFFER, stdin);
    s[strcspn(s, "\n")] = 0;
}

void generateFirstPassword(char *name, char *district, char *password) {
    int i;
    int passwordIndex = 0;

    for (i = 0; name[i] != '\0'; i++) {
        if (isVowel(name[i])) {
            password[passwordIndex] = name[i];
            passwordIndex++;
        }
    }

    for (i = 0; district[i] != '\0'; i++) {
        if (isVowel(district[i])) {
            password[passwordIndex] = district[i];
            passwordIndex++;
        }
    }

    password[passwordIndex] = '\0';
}

int isVowel(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }
    return 0;
}
