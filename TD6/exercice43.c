#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.14159265358979323846

struct Point {
  float x;
  float y;
};

int compte(struct Point *point) {
  float x = point->x;
  float y = point->y;
  if (pow(x, 2) + pow(y, 2) <= 1.0) {
    return 1;
  }
  return 0;
}

float donnerPiSurQuatre(int n) {
  struct Point point;
  int p = 0;
  for (int i = 0; i < n; i++) {
    point.x = (float)rand()/RAND_MAX;
    point.y = (float)rand()/RAND_MAX;
    p += compte(&point);
  }
  return (float)p/n;
}

int estimer(float erreur) {
  float estimation = 0;
  int n = 0, k = 100000;
  while (1) {
    while (fabs(estimation*4 - PI) >= erreur) {
      n = n + k;
      estimation = donnerPiSurQuatre(n);
      printf("Boucle n = %d, Estimation = %f\n", n, estimation * 4);
    }
    if (k == 1) {
      break;
    } else {
      n = n - k;
      k = k / 10;
      estimation = donnerPiSurQuatre(n);
    }
  }

  printf("Il faut tirer environ %d flechettes pour etimer Pi !\n", n);
  return 0;
}

int main(void) {
  srand(time(NULL));
  estimer(0.001);
  return 0;
}
