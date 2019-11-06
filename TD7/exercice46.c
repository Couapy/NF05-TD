#include <stdio.h>
#include <stdlib.h>

int * operationVecteur(int n, int *u, int *v, int signe) {
  int *w = malloc(n*sizeof(int));

  for (int i = 0; i < n; i++) {
    *(w+i) = *(u+i) + signe * (*(v+i));
  }

  return w;
}

int* sommeVecteur(int n, int* u, int* v) {
  return operationVecteur(n, u, v, 1);
}

int* soustractionVecteur(int n, int* u, int* v) {
  return operationVecteur(n, u, v, -1);
}

int produitScalaire(int n, int *u, int *v) {
  int k = 0;

  for (int i = 0; i < n; i++) {
    k += *(u+i) * (*v+i);
  }

  return k;
}

void afficherVecteur(int *u, int n) {
  printf("( ");
  for (int i = 0; i < n; i++) {
    printf("%d ", *(u+i));
  }
  printf(")\n");
}

int* saisirVecteur(int n) {
  static int v = 0;
  v++;
  int *u = malloc(n*sizeof(int));
  printf("======================================================\n");
  printf("Saisie d'un nouveau vecteur\n\n");

  for (int i = 0; i < n; i++) {
    printf("Entrez le composante n%d du vecteur n%d : ", i+1, v);
    scanf(" %d", u+i);
  }

  printf("Vous avez entre : ");
  afficherVecteur(u, n);
  printf("\n");

  return u;
}

int main(void) {
  int N, *u, *v, *w, *k;

  printf("Quelle est la taille de vos vecteur ? ");
  scanf(" %d", &N);

  u = saisirVecteur(N);
  v = saisirVecteur(N);
  w = sommeVecteur(N, u, v);
  k = soustractionVecteur(N, u, v);

  printf("La somme des deux vecteurs est : ");
  afficherVecteur(w, N);
  printf("La soustraction des deux vecteurs est : ");
  afficherVecteur(k, N);
  printf("Le produit scalaire vaut : %d", produitScalaire(N, u, v));

  free(u);
  free(v);
  free(w);
  free(k);

  return 0;
}
