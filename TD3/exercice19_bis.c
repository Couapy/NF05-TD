#include <stdio.h>
#include <math.h>

float integraliser(long n) {
  float integrale = 0.0, division;
  division = 9.90/n;

  for (float i = 0.10; i < 10; i+=division) {
    integrale += (exp(-i) / pow(i, 3)) * division;
  }

  return integrale;
}

int main(void) {
  long n = 1;
  float integrale = 41.62914, approximation;

  approximation = integraliser(n);
  while (approximation - integrale > 0.01) {
    n+=100;
    approximation = integraliser(n);
    // printf("n=%d, %.5f\n", n, approximation);
  }

  printf("Il faut diviser l'intervalle par %d pour obtenir une erreur inferieure a 0.01", n-1);

  // Soit f la fonction d´efinie sur l’intervalle [0.1, 10] par f(x) = exp(−x)/x^3. Calculer son
  // int´egrale sur cet intervalle `a 10^−2 pr`es en utilisant la m´ethode des rectangles.
  return 0;
}
