#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char string[512];
  int majuscules = 0, minuscules = 0, espaces = 0, length = 0;

  printf("Entrez la chaine de caracteres : \n");
  gets(string);
  length = strlen(string);
  printf("Vous avez entre : %s\n", string);

  for (int i = 0; i < length; i++) {
    if ('A' <= string[i] && string[i] <= 'Z') {
      majuscules++;
    } else if ('a' <= string[i] && string[i] <= 'z') {
      minuscules++;
    } else if (string[i] == ' ') {
      espaces++;
    }
  }

  printf("Dans votre chaine de caracteres, il y a : \n");
  printf("%d majuscules\n", majuscules);
  printf("%d minuscules\n", minuscules);
  printf("%d espaces\n", espaces);

  return 0;
}
