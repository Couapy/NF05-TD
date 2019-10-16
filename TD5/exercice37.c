#include <stdio.h>
#include <stdlib.h>

// int a[3][3] = {
//   {1, 2, 3},
//   {4, 5, 6},
//   {7, 8, 9}
// }, b[3][3] = {
//   {12, 7, 45},
//   {27, 2, 11},
//   {0, 12, 9}
// };
// int a_x = 3, a_y = 3;
// int b_x = 3, b_y = 3;

int a[2][2] = {
  {2, 5},
  {4, 2},
}, b[2][2] = {
  {1, 0},
  {1, 1}
};
int a_x = 2, a_y = 2;
int b_x = 2, b_y = 2;

void afficher(void);
void addition(void);
void soustraction(void);
void calculer(int signe);

void afficher(void) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void addition(void) {
  printf("Addition\n");
  calculer(1);
}

void soustraction(void) {
  printf("Soustraction\n");
  calculer(-1);
}

void calculer(int signe) {
  if (a_x == b_x && a_y == b_y) {
    int res[3][3] = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
    };
    for (int i = 0; i < a_x; i++) {
      for (int j = 0; j < a_y; j++) {
        res[i][j] = a[i][j] + (signe * b[i][j]);
        printf("%d ", res[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("On ne peut calculer car les dimensions ne sont pas les mêmes :/ \n");
  }
}

int multiplier(void) {
  printf("Mutlipication\n");
  int res[a_x][b_y];
  if (a_y != b_x) {
    printf("On ne peut pas calculer\n");
    return 0;
  }

  for (int i = 0; i < a_x; i++) {
    for (int j = 0; j < b_y; j++) {
      res[i][j] = 0;
      for (int k = 0; k < a_y; k++) {
        res[i][j] += a[i][k] * b[k][j];
      }
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }

  return 1;
}

int main(void) {

  afficher();
  addition();
  soustraction();
  multiplier();

  return 0;
}
