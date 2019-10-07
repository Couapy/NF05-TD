#include <stdio.h>
#include <math.h>

int estPremier(int nb) {
  int i = 2;
  float racine = sqrt(nb);

  while (i <= racine) {
    if (nb % i == 0) {
      return 0;
    }
    i++;
  }

  return 1;
}

int main(void) {
  printf("Les nombres premiers sont :\n\n");

  for (int i = 1; i < 50; i++) {
    if (estPremier(i)) {
      printf("%d\n", i);
    }
  }

  return 0;
}
