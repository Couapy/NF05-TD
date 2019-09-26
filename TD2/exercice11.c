#include <stdio.h>
#include <math.h>

int binaireConvertir(int x) {
  //On converti le nombre en binaire
  int i, binaire, reste;

  i = 1;
  binaire = 0;
  reste = 1;
  while (x != 0) {
    reste = x % 2;
    x = x / 2;
    binaire = binaire + reste * i;
    i = i * 10;
  }

  return binaire;
}

int inverser(int binaire, int p, int n) {
  int A, B;
  A = pow(10, n-1);
  B = A * pow(10, p);
  for (int j = A; j < B; j = j * 10) {
    if (binaire / j == 1) {
      binaire -= j;
    } else {
      binaire += j;
    }
  }
  return binaire;
}

int decimalConvertir(int binaire) {
  int bin, w;
  w = 0;
  bin = 0;
  while (binaire != 0) {
    bin += pow(2, w) * (binaire % 10);
    binaire = binaire / 10;
    w++;
  }
  return bin;
}

int main(void) {
  int x, p, n, binaire, resultat;

  //On initialise les variables
  printf("X = ");
  scanf(" %d", &x);
  printf("N = ");
  scanf(" %d", &n);
  printf("P = ");
  scanf(" %d", &p);

  binaire = binaireConvertir(x);
  binaire = inverser(binaire, p, n);
  resultat = decimalConvertir(binaire);

  printf("\nLe resultat final est : %d\n", resultat);

  return 0;
}
