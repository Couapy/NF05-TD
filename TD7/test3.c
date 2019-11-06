#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int *entier = malloc(sizeof(int)); // *entier pointe vers une variable pas à nous
  int i = 3;
  entier = &i; // entier pointe vers i

  // OU

  int *entier = malloc(sizeof(int)); // *entier pointe vers une variable pas à nous
  *entier = 3;

  return 0;
}
