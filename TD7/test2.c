#include <stdio.h>
#include <stdlib.h>

void afficher(int *k) {
  for (int i = 0; i < 4; i++) {
    printf("%d ", k[i]);
  }
}

int main(void) {

  int *test = malloc(4*sizeof(int));
  test[0] = 1;
  test[1] = 2;
  test[2] = 3;
  test[3] = 4;

  afficher(test);

  return 0;
}
