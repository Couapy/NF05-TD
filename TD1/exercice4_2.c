#include <stdio.h>

int main() {
  float i = 5.0;
  float j = 9.0;
  float k = 0.0;

  printf("i=%f, j=%f\n", i, j);

  printf("Permutation !\n");
  k = j;
  j = i;
  i = k;

  printf("i=%f, j=%f\n", i, j);

  return 0;
}
