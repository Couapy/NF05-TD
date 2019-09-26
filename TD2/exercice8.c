#include <stdio.h>

int main() {
  int nombre;

  printf("Quel est le nombre à convertir ? ");
  scanf(" %d", &nombre);
  printf("Le nombre %d est %o en octal.", nombre, nombre);

  return 0;
}
