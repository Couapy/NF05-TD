#include <stdio.h>

void transposer(int x, int y, int tab[][y]) {
  int res[y][x];
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      res[j][i] = tab[i][j];
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int matrice_x = 2, matrice_y = 2;
  int matrice[2][2] = {
    {1, 2},
    {3, 4}
  };

  transposer(matrice_x, matrice_y, matrice);

  return 0;
}
