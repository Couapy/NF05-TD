#include <stdio.h>
#include <math.h>

void saisir(char name, float *number) {
  printf("Saisissez le nombre %c : ", name);
  scanf(" %f", number);
}

int main(void) {
  float a, b, c, delta, x_un, x_deux;
  saisir('a', &a);
  saisir('b', &b);
  saisir('c', &c);

  delta = pow(b, 2) - (4*a*c);
  if (delta == 0) {
    x_un = (-b)/pow(a, 2);
  } else if (delta > 0) {
    x_un = (-b-sqrt(delta))/pow(a, 2);
    x_deux = (b-sqrt(delta))/pow(a, 2);
    printf("Les solutions sont : x1=%f et x2=%f", x_un, x_deux);
  } else {
    printf("Il n'y a pas de solution.");
  }

  return 0;
}
