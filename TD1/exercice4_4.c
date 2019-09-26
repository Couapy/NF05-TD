#include <stdio.h>

int main() {
  int a = 5;
  int b = 9;
  int max;
  int min;

  if (a>b) {
    max = a;
    min = b;
  } else {
    max = b;
    min = a;
  }

  printf("max=%d, min=%d", max, min);

  return 0;
}
