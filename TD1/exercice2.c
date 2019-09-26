#include <stdio.h>

int main(void) {
  int i = 2;
  int j = 3;

  //Division de j par i
  printf("Division de i par j = %f\n", (float)i/j);
  /**
   * Deux choses ne vont pas :
   *  - on divise par 0 ce qui renvoie une exception...
   *  - on utilise %d au lieu de %f qui utilise un entier au lieu d'un réel
   */
  return 0;
}
