#include <stdio.h>
#define PI 3.1416

int main() {
  int R, H;
  float V, B;
  printf("Pi vaut %f\n", PI);

  printf("Entrez le rayon : ");
  scanf(" %d", &R);
  printf("Entrez la hauteur : ");
  scanf(" %d", &H);

  B = PI * R * R;
  V = (1/3.0) * B * H;
  printf("Le volume du cone est : %.2f\n", V);

  return 0;
}
