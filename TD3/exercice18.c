#include <stdio.h>
#include <math.h>

int main(void) {
  int n = 1;
  float somme = 0, reste = 0, tolerance = pow(10, -3);

  while (reste <= tolerance) {
    somme += 1/pow(n, 2);
    reste = 1/pow(n, 2);
    n++;
  }

  printf("La somme est S = %f avec une erreur inférieure à 10^(-3)", somme);

  // Calculer la somme S de la serie dont le n^eme terme est 1/n2 `a epsilon = 10−3 pr`es : Si
  // S∗ est la valeur de la somme infinie et S la valeur de la somme des n premiers termes alors
  // S∗ − S < epsilon.
  // Trouver la condition d’arrˆet sur le dernier terme en fonction de la valeur d’epsilon
  return 0;
}
