#include <stdio.h>

int main() {
  float A;
  int B, H;
  printf("B: ");
  scanf(" %d", &B);
  printf("H: ");
  scanf(" %d", &H);

  A = 0.5 * B * H;

  printf("L'aire vaut %f", A);

  return 0;
}
