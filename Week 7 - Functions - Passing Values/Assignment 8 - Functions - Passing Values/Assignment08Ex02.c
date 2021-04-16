#include <stdio.h>

int arredonda(float x) {
  int isNegative = 0;

  if (x < 0) {
    isNegative = 1;
  }
  
  float decimal = x - ((int) x);

  if (isNegative) {
    decimal *= -1;
  }

  if (decimal * 10 < 5) {
    return (int) x;
  }
  if (isNegative) {
    return (int) x - 1;
  }
  return (int) x + 1;
}

int main(void) {
  printf("%d\n", arredonda(-1.0));
  printf("%d\n", arredonda(-1.2));
  printf("%d\n", arredonda(-1.4));
  printf("%d\n", arredonda(-1.5));
  printf("%d\n", arredonda(-1.7));
  printf("%d\n", arredonda(-1.9));
  printf("%d\n", arredonda(-2.0));

  printf("%d\n", arredonda(1.0));
  printf("%d\n", arredonda(1.2));
  printf("%d\n", arredonda(1.4));
  printf("%d\n", arredonda(1.5));
  printf("%d\n", arredonda(1.7));
  printf("%d\n", arredonda(1.9));
  printf("%d\n", arredonda(2.0));
  return 0;
}