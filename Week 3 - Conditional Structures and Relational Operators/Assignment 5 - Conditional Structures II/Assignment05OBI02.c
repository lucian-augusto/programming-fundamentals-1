#include <stdio.h>

int main(void) {
  char result = ' ';
  const int courtSize[2] = {432, 468};
  int ballLandingCoordinates[2];

  scanf("%d %d", &ballLandingCoordinates[0], &ballLandingCoordinates[1]);

  for (int i = 0; i < 2; i++) {
    if (ballLandingCoordinates[i] > courtSize[i] || ballLandingCoordinates[i] < 0) {
      result = 'f';
      break;
    } 
    result = 'd';
  }

  printf("%c", result);
  return 0;
}