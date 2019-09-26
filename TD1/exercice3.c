#include <stdio.h>

int main() {
  int entier = 1;
  char caractere = 2;
  float reel = 1.2;
  double double_reel = 1.0000000000000000000000000000000;
  short short_reel = 1.2222;

  printf("Taille d'un entier : %d octets\n", sizeof(entier));
  printf("Taille d'un caractere : %d octets\n", sizeof(caractere));
  printf("Taille d'un reel : %d octets\n", sizeof(reel));
  printf("Taille d'un double : %d octets\n", sizeof(double_reel));
  printf("Taille d'un short : %d octets\n", sizeof(short_reel));

  return 0;
}
