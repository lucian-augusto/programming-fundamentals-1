/* =============================================================================
 * Libraries
 * ========================================================================== */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* =============================================================================
 * Macro Definitions
 * ========================================================================== */
#define X_MIN 0
#define X_MAX 2
#define Y_MIN -2
#define Y_MAX 2

/* =============================================================================
 * Struct Declarations
 * ========================================================================== */
typedef struct {
  float x, y;
} Point;

/* =============================================================================
 * Function Prototypes Header
 * ========================================================================== */
int captureCoordinates(Point *p);
float captureValue(char coordinate);
char isInside(Point *p);
void printVeredict(Point *p);

/* =============================================================================
 * Main
 * ========================================================================== */
int main(void) {
  Point p;
  int continua;

  do {
    continua = captureCoordinates(&p);

    printVeredict(&p);
  } while (continua);

  printf("\nFim do programa...");

  return 0;
}

/* =============================================================================
 * Functions
 * ========================================================================== */
int captureCoordinates(Point *p) {
  int keepRunning = 1;

  p->x = captureValue('x');
  p->y = captureValue('y');

  if (p->x == 0 && p->y == 0) {
    keepRunning = 0;
  }

  return keepRunning;
}

float captureValue(char coordinate) {
  float f;

  printf("Por favor insira o valor da coordenada %c: ", coordinate);
  scanf("%f", &f);

  return f;
}

char isInside(Point *p) {
  char isInside = 'i'; // interno

  if (p->x > 2 || p->x < 0) {
    isInside = 'e';
  }

  if (fabs(p->y) > p->x) {
    isInside = 'e'; // externo
  }

  return isInside;
}

void printVeredict(Point *p) {
  char veredict;

  veredict = isInside(p);

  switch (veredict) {
  case 'i':
    printf("Interior\n");
    break;
  case 'e':
    printf("Exterior\n");
    break;
  default:
    printf("Erro!\n");
  }
}
