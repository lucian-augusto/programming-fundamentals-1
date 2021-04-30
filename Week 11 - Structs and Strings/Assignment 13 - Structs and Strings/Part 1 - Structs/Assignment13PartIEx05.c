#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX_LENGTH 100

struct funcionario {
    int mat; /* matricula do funcionario */
    char nome[100]; /* inicial do nome do funcionario */
    int sup; /* matricula do superior imediato */
};
typedef struct funcionario Funcionario;

void * allocateArray(int size);
Funcionario* createTestData();
Funcionario* determinaSubordinado(Funcionario** vet, int n, int mat, int *pTam);
void fillName(char *a, char *n);
int indiceFuncionario(Funcionario* vet, int n, int mat);
void printFuncionarioArray(Funcionario *f, int amount);

int main(void) {
    Funcionario *f;
    Funcionario *selectedEmployees;
    int subAmount;
    int testMat = 126;
    int size = 6;
    int i;

    printf("Criando vetor de testes...\n");
    f = createTestData();

    printf("Testando função \"indiceFuncionario\":\n");
    for (i = 122; i < 131; i++) {
        printf("Índice do funcionário de matrícula %d: %d\n", i, indiceFuncionario(f, size, i));
    }

    printf("Testando função \"determinaSubordinado\":\n");

    selectedEmployees = determinaSubordinado(&f, size, testMat, &subAmount);

    printf("%d funcionários são subordinados do portador da matrícula %d\nSão eles:\n", subAmount, testMat);

    printFuncionarioArray(selectedEmployees, subAmount);

    free(f);
    free(selectedEmployees);

    return 0;
}

// (a)
int indiceFuncionario(Funcionario* vet, int n, int mat) {
    int i;

    for (i = 0; i < n; i++) {
        if (vet[i].mat == mat) {
            return i;
        }
    }

    return -1;
}

// (b) Challenge
Funcionario* determinaSubordinado(Funcionario** vet, int n, int mat, int *pTam) {
    int i;
    Funcionario *subordinates;
    int *indexes;
    *pTam = 0;

    indexes = (int*) allocateArray(n * sizeof(int));

    for (i = 0; i < mat; i++) {
        if ((*vet)[i].sup == mat) {
            *pTam += 1;
            *indexes = i;
            indexes++;
        }
    }

    subordinates = (Funcionario*) allocateArray(*pTam * sizeof(Funcionario));
    indexes -= *pTam; // Returning the pointer to the first position

    for (i = 0; i < *pTam; i++) {
        subordinates[i] = (*vet)[indexes[i]];
    }

    return subordinates;
}

// Utilities
void * allocateArray(int size) {
    void *a;

    a = malloc(size);

    if (a == NULL) {
        printf("Erro ao alocar vetor.");
    }

    return a;
}

Funcionario* createTestData() {
    Funcionario *f;

    f = (Funcionario*) allocateArray(6 * sizeof(Funcionario));

    f[0].mat = 123;
    fillName(f[0].nome, "Luiza");
    f[0].sup = 125;

    f[1].mat = 124;
    fillName(f[1].nome, "Diana");
    f[1].sup = 129;

    f[2].mat = 125;
    fillName(f[2].nome, "Gina");
    f[2].sup = 126;

    f[3].mat = 126;
    fillName(f[3].nome, "Celia");
    f[3].sup = -1;

    f[4].mat = 128;
    fillName(f[4].nome, "Beatriz");
    f[4].sup = 126;

    f[5].mat = 129;
    fillName(f[5].nome, "Ana");
    f[5].sup = 128;

    return f;
}

void fillName(char *a, char *n) {
    int i;

    for (i = 0; n[i] != '\0'; i++) {
        a[i] = n[i];
    }
    a[i++] = '\0';
}

void printFuncionarioArray(Funcionario *f, int amount) {
    int i;

    for (i = 0; i < amount; i++) {
        printf("{\n\tmat: %d\n\tnome: %s\n\tsup: %d\n}\n", f[i].mat, f[i].nome, f[i].sup);
    }
}
