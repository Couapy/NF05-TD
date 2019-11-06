#include <stdio.h>
#include <stdlib.h>

int n;

void nombre(void) {
  printf("n = ");
  scanf(" %d", &n);
}

int main(void) {

  nombre();
  printf("n = %d", n);

  return 0;
}
