#include <stdio.h>
#include <math.h>

int main() {
  int entier, bin, i;

  printf("Entrez le nombre binaire : ");
  scanf(" %d", &entier);

  i = 0;
  bin = 0;
  while (entier != 0) {
    bin += pow(2, i) * (entier % 10);
    entier = entier / 10;
    i++;
  }

  printf("Le nombre %d\n", bin);

  return 0;
}
