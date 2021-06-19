/* =============================================================================
 * Libraries
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* =============================================================================
 * Macro Definitions
 * ========================================================================== */
#define MAX_RANDOM_NUMBER 100
/* =============================================================================
 * Struct Declarations
 * ========================================================================== */
typedef struct {
  int n;
  int *v;
  float media;
  int maior;
  int menor;
  int m;
  int *v2;
} DadosVetor;
/* =============================================================================
 * Function Prototypes Header
 * ========================================================================== */
void *allocateMemory(int size);
void calculaDados(DadosVetor *s);
void calculateM(DadosVetor *s);
void calculaV2(DadosVetor *s);
int captureNumberOfElements();
int *generateRandomArray(int numberElements);
void printStruct(DadosVetor *s);
/* =============================================================================
 * Main
 * ========================================================================== */
int main(void) {
  DadosVetor dv;
  srand(time(NULL));

  dv.n = captureNumberOfElements();

  dv.v = generateRandomArray(dv.n);

  calculaDados(&dv);

  calculaV2(&dv);

  printStruct(&dv);

  free(dv.v);
  free(dv.v2);

  return 0;
}

/* =============================================================================
 * Functions
 * ========================================================================== */
void *allocateMemory(int size) {
  void *a;

  a = malloc(size);

  if (a == NULL) {
    printf("Erro ao alocar memória");
  }

  return a;
}

void calculaDados(DadosVetor *s) {
  int i;

  s->media = s->v[0];
  s->maior = s->v[0];
  s->menor = s->v[0];
  for (i = 1; i < s->n; i++) {
    s->media += s->v[i];

    if (s->v[i] > s->maior) {
      s->maior = s->v[i];
    }

    if (s->v[i] < s->menor) {
      s->menor = s->v[i];
    }
  }
  s->media /= (float)s->n;
}

void calculateM(DadosVetor *s) {
  int i;
  s->m = 0;

  for (i = 0; i < s->n; i++) {
    if (s->v[i] > s->media) {
      s->m++;
    }
  }
}

void calculaV2(DadosVetor *s) {
  int i;
  int v2Index = 0;
  calculateM(s);

  s->v2 = (int *)allocateMemory(s->m * sizeof(int));

  for (i = 0; i < s->n; i++) {
    if (s->v[i] > s->media) {
      s->v2[v2Index] = s->v[i];
      v2Index++;
    }
  }
}

int captureNumberOfElements() {
  int numberElements;

  printf("Por favor, insira o número de elementos (min. 2): ");
  scanf("%d", &numberElements);
  while (numberElements < 2) {
    printf("É necessário pelo menos 2 termos para um vetor. Por favor tente "
           "novamente: ");
    scanf("%d", &numberElements);
  }
  return numberElements;
}

int *generateRandomArray(int numberElements) {
  int *a;
  int i;

  a = (int *)allocateMemory(numberElements * sizeof(int));

  for (i = 0; i < numberElements; i++) {
    a[i] = rand() % (MAX_RANDOM_NUMBER + 1); // 0-100 interval
  }

  return a;
}

void printStruct(DadosVetor *s) {
  int i;
  printf("Número de elementos do vetor: %d\n", s->n);

  printf("Vetor: \n[ ");
  for (i = 0; i < s->n; i++) {
    printf("%d ", s->v[i]);
  }
  printf("]\n");

  printf("Média dos elementos: %.3f\n", s->media);

  printf("Maior elemento: %d\n", s->maior);

  printf("Maior elemento: %d\n", s->menor);

  printf("Número de elementos acima da média: %d\n", s->m);

  printf("Vetor 2: \n[ ");
  for (i = 0; i < s->m; i++) {
    printf("%d ", s->v2[i]);
  }
  printf("]\n");
}
