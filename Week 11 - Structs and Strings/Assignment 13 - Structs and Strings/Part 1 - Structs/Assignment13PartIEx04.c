#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ALUNOS 100

typedef struct {
    float p[3];
    float M;
} Provas;

typedef struct {
    int ra;
    int frequencia;
    Provas Ps;
} Aluno;

void calculateGlobalExamMean(float *meanArray, Aluno *studentArray, int amount);
void calculateGlobalExamStandardDeviation(float *sdArray, Aluno *studentArray, float *meanArray, int amount);
void captureAlunoInfo(Aluno *a);
void captureExamGrade(float *g);
void fillAlunoArray(Aluno *a, int amount);
void printAlunos(Aluno *a, int amount);
void printMeansAndStandardDeviations(float *meanArray, float *sdArray, int size);

int main(void) {
    int n;
    float desvios_Ps[3]={0.0, 0.0, 0.0}, medias_Ps[3]={0.0, 0.0, 0.0};
    Aluno vetAlunos[MAX_ALUNOS];
    scanf("%d", &n);
    /* COMPLETE AQUI */
    fillAlunoArray(vetAlunos, n);

    calculateGlobalExamMean(medias_Ps, vetAlunos, n);
    calculateGlobalExamStandardDeviation(desvios_Ps, vetAlunos, medias_Ps, n);

    printAlunos(vetAlunos, n);
    printMeansAndStandardDeviations(medias_Ps, desvios_Ps, n);

    return 0;
}

void calculateGlobalExamMean(float *meanArray, Aluno *studentArray, int amount) {
    int i, j;

    for (i = 0; i < amount; i++) {
        for (j = 0; j < amount; j++) {
            meanArray[i] += studentArray[j].Ps.p[i];
        }
        meanArray[i] /= amount;
    }
}

void calculateGlobalExamStandardDeviation(float *sdArray, Aluno *studentArray, float *meanArray, int amount) {
    int i, j;

    for (i = 0; i < amount; i++) {
        for (j = 0; j < amount; j++) {
           sdArray[i] += pow(fabsf(studentArray[j].Ps.p[i] - meanArray[i]), 2);
        }
        sdArray[i] = sqrt(sdArray[i]/amount);
    }
}

void captureAlunoInfo(Aluno *a) {
    int provasAmount = 3;
    int i;
    Provas *p;
    p = &a->Ps;
    p->M = 0;
    scanf("%d", &a->ra);

    for (i = 0; i < provasAmount; i++) {
        captureExamGrade(&p->p[i]);
        p->M += p->p[i];
    }
    p->M /= provasAmount;

}

void captureExamGrade(float *g) {
    scanf("%f", g);

    while (*g < 0 || *g > 10) {
        printf("Nota Inválida! Por favor, tente novamente: ");
        scanf("%f", g);
    }
}

void fillAlunoArray(Aluno *a, int amount) {
    int i;

    for (i = 0; i < amount; i++) {
        captureAlunoInfo(&a[i]);
    }
}

void printAlunos(Aluno *a, int amount) {
    int i, j;

    for (i = 0; i < amount; i++) {
        printf("RA: %d\n", a[i].ra);
        for (j = 0; j < amount; j++) {
            printf("Prova %d: %f\n", j, a[i].Ps.p[j]);
        }
        printf("Média: %f\n", a[i].Ps.M);
        printf("----------------\n");
    }
}

void printMeansAndStandardDeviations(float *meanArray, float *sdArray, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Média geral P%d: %f\n", i, meanArray[i]);
        printf("Desvio padrão P%d: %f\n", i, sdArray[i]);
    }
}
