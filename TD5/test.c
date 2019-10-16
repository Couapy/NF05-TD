#include <stdio.h>

int dim = 3;

void afficher(int a[][dim]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int a[3][3] = { {1,2,3}, {4,5,6}, {7,8,9}};

  afficher(a);

  return 0;
}
