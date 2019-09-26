#include <stdio.h>

int main(void) {

  int nombre;
  printf("Quel est le nombre a convertir ? ");
  scanf(" %d", &nombre);
  printf("Le nombre %d est %x en hexadecimal.", nombre, nombre);

  return 0;
}
