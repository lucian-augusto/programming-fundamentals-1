/* =============================================================================
 * Libraries
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>

/* =============================================================================
 * Macro Definitions
 * ========================================================================== */

/* =============================================================================
 * Struct Declarations
 * ========================================================================== */

/* =============================================================================
 * Function Prototypes Header
 * ========================================================================== */
int **alocaMatriz(int size);
int *alocaVetor(int length);
int captureItinerarySize();
int captureMatrixSize();
int checkAllocatedArray(int *a);
int custoCidades(int *cidades, int nCidades, int **m);
void fillArray(int *m, int size, int limit);
void fillMatrix(int **m, int size);
void freeMatrix(int **m, int size);

/* =============================================================================
 * Main
 * ========================================================================== */
int main(void) {
  int size;
  int **costMatrix;
  int itinerarySize;
  int *itinerary;
  int totalCost;

  size = captureMatrixSize();

  costMatrix = alocaMatriz(size);

  fillMatrix(costMatrix, size);

  if (costMatrix == NULL) {
    printf("Erro na alocação da Matriz. Saindo...");
    return 0;
  }

  itinerarySize = captureItinerarySize();

  itinerary = alocaVetor(itinerarySize);

  if (!checkAllocatedArray(itinerary)) {
    printf("Erro na alocação do vetor. Saindo...");
    free(itinerary);
    return 0;
  }

  fillArray(itinerary, itinerarySize, size);

  totalCost = custoCidades(itinerary, itinerarySize, costMatrix);

  printf("O custo total do Itinerário será: $%02d.00.", totalCost);

  freeMatrix(costMatrix, size);
  free(itinerary);

  return 0;
}

/* =============================================================================
 * Functions
 * ========================================================================== */
int **alocaMatriz(int size) {
  int **m;

  m = (int **)malloc(size * sizeof(int *));

  int i;
  for (i = 0; i < size; i++) {
    m[i] = (int *)malloc(size * sizeof(int));
    if (!checkAllocatedArray(m[i])) {
      freeMatrix(m, size);
      return NULL;
    }
  }
  return m;
}

int *alocaVetor(int length) {
  int *a;

  a = (int *)malloc(length * sizeof(int));

  return a;
}

int custoCidades(int *cidades, int nCidades, int **m) {
  int i;
  int totalCost = 0;

  for (i = 1; i < nCidades; i++) {
    totalCost += m[cidades[i - 1]][cidades[i]];
  }

  return totalCost;
}

int captureItinerarySize() {
  int length;

  printf("Por favor, insira o tamanho do itinerário: ");
  scanf("%d", &length);

  while (length < 2) {
    printf("O itinerário deve conter pelo menos duas cidades (elementos). Por "
           "favor, tente novamente: ");
    scanf("%d", &length);
  }

  return length;
}

int captureMatrixSize() {
  int length;

  printf("Por favor, insira o tamanho da matriz (quadrada): ");
  scanf("%d", &length);

  while (length < 2) {
    printf("A Matriz precisa ter no mínimo 2x2. Por favor, tente novamente: ");
    scanf("%d", &length);
  }

  return length;
}

int checkAllocatedArray(int *a) {
  if (a == NULL) {
    printf("Erro ao alocar memória para o vetor.");
    return 0;
  }
  return 1;
}

void fillArray(int *m, int size, int limit) {
  int i = 0;

  while (i < size) {
    printf("Por favor, insira a %da cidade do itinerário: ", i + 1);
    scanf("%d", &m[i]);
    if (m[i] >= limit || m[i] < 0) {
      printf("Destino inválido. O valor deve estar entre (incluindo) 0 e %d\n",
             limit - 1);
    } else {
      i++;
    }
  }
}

void fillMatrix(int **m, int size) {
  int i, j;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      if (i == j) {
        printf("Mesma cidade. Custo: 0.\n");
        m[i][j] = 0;
      } else {
        printf("Por favor, insira o termo %dx%d da matriz de custos: ", i, j);
        scanf("%d", &m[i][j]);
      }
    }
  }
}

void freeMatrix(int **m, int size) {
  int i;
  for (i = 0; i < size; i++) {
    free(m[i]);
  }
  free(m);
}
