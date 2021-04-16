#include <stdio.h>
#include <math.h>

int main(void) {
  int part1, part2, i;

  for (i = 1000; i <= 9999; i++) {
    part1 = i / 100;
    part2 = i % 100;

    if (pow(part1 + part2, 2) == i) {
      printf("%02d + %02d -> %d * %d = %d\n", part1, part2, part1 + part2, part1 + part2, i);
    }
  }
  return 0;
}