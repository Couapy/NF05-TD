#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int tab[] = {1, 2, 3, 4};
  int a, b, temp;

  for (int i = 0; i < 4; i++) {
    printf("tab[%d] = %d\n", i, tab[i]);
  }

  printf("a = ");
  scanf(" %d", &a);

  printf("b = ");
  scanf(" %d", &b);

  temp = tab[b];
  tab[b] = tab[a];
  tab[a] = temp;

  for (int i = 0; i < 4; i++) {
    printf("tab[%d] = %d\n", i, tab[i]);
  }

  return 0;
}
