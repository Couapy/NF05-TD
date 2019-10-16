#include <stdio.h>

void afficher(int **a) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int a[3][3] = { {1,2,3}, {4,5,6}, {7,8,9}};
  //printf("%d\n", a[0][0] );
  afficher(a);

  return 0;
}
