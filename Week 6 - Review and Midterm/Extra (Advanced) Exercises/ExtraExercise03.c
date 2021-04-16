#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, diamondSize, axis,i, j;
  
  scanf("%d", &n);

  diamondSize = (2 * n) + 1;
  axis = diamondSize / 2 ;

  for (i = 0; i < diamondSize; i++) {
    for (j = 0; j < diamondSize; j++) {
      if (i <= axis) {
        if ((j < axis - i) || (j > axis + i)) {
          printf(" ");
        } else {
          printf("#");
        }
      } else {
        if ((j < i - axis) || (j > 3 * axis - i)) {
          printf(" ");
        } else {
          printf("#");
        }
      }
    }
    printf("\n");
  }

  return 0;
}