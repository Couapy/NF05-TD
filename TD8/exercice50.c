#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saisirVecteur(int* vecteur, int taille) {
  printf("\n");
  for (int i = 0; i < taille; i++) {
    printf("vecteur[%d] = ", i+1);
    scanf(" %d", &vecteur[i]);
  }
}

int enregistrerVecteur(FILE* fichier, int* vecteur, int taille) {
  for (int i = 0; i < taille; i++) {
    fprintf(fichier, "%d ", vecteur[i]);
  }
  fprintf(fichier, "\n");
}

void stockerVecteurs(int m, int n) {
  FILE *fichier = NULL;
  int *vecteur = NULL;

  vecteur = (int*)malloc(n * sizeof(int));
  fichier = fopen("files/files/exo50.txt", "w+");

  for (int i = 0; i < m; i++) {
    saisirVecteur(vecteur, n);
    enregistrerVecteur(fichier, vecteur, n);
  }

  free(vecteur);
  fclose(fichier);
}

void faireSomme(int m, int n) {
  FILE *fichier = NULL;
  int *vecteur, *res;
  vecteur = (int*)malloc(n * sizeof(int));
  res = (int*)malloc(n * sizeof(int));

  fichier = fopen("files/exo50.txt", "r");

  char string[1024];
  int i;
  for (int i = 0; i < n; i++) {
    res[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      fscanf(fichier, "%d", &vecteur[j]);
      res[j] += vecteur[j];
    }
  }

  free(vecteur);
  fclose(fichier);

  printf("\nLe vecteur somme est :\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", res[i]);
  }
  free(res);
}

int main(void) {
  int m, n;

  printf("Combien de vecteurs a-t-il ? ");
  scanf(" %d", &m);
  printf("Quelle est la taille des vecteurs ? ");
  scanf(" %d", &n);

  stockerVecteurs(m, n);
  faireSomme(m, n);

  return 0;
}

// 1. Ecrire une proc´edure/fonction permettant de stocker M vecteurs r´eels de taille N ´
// (M et N seront saisis par l’utilisateur) dans un fichier avec un nom donn´e par
// l’utilisateur.
// 2. Ecrire une proc´edure/fonction permettant de calculer la somme des ´el´ements des ´
// deux vecteurs dans le fichier pr´ec´edent et ajouter ce r´esultat de calcul dans ce fichier.
