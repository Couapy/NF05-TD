#include <stdio.h>

int main() {
  int decimal, binaire, i, reste;

  printf("Entrez le nombre decimal : ");
  scanf(" %d", &decimal);

  i = 1;
  binaire = 0;
  while (decimal != 0) {
    reste = decimal % 2;
    decimal = decimal / 2;
    binaire = binaire + reste * i;
    i = i * 10;
  }

  printf("Le binaire est : %d", binaire);

  return 0;
}
