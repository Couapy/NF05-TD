#include <stdio.h>
#include <stdlib.h>

int** genererMatrice(int n, int p) {
  int **matrice = (int**) malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    *(matrice+i) = (int*)malloc(p * sizeof(int));
  }
  return matrice;
}

void saisirMatrice(int **matrice, int n, int p) {
  printf("\n=============================================\n\n");
  printf("Saisie d'une matrice de taile %d*%d :\n", n, p);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      printf("matrice[%d][%d] = ", i, j);
      scanf(" %d", &matrice[i][j]);
    }
  }
  printf("\n");
}

void afficherMatrice(int **matrice, int n, int p) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      printf("%d ", matrice[i][j]);
    }
    printf("\n");
  }
}

void libererMatrice(int **matrice, int n) {
  for (int i = 0; i < n; i++) {
    free(*(matrice+i));
  }
  free(matrice);
}

void calculMatrice(int signe, int **matrice1, int **matrice2, int n, int p) {
  printf("\n=============================================\n\n");
  if (signe == 1) {
    printf("Somme des matrices : \n");
  } else {
    printf("Soustraction des matrices : \n");
  }
  int somme;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      somme = matrice1[i][j] + signe * matrice2[i][j];
      printf("%d ", somme);
    }
    printf("\n");
  }
}

void sommeMatrice(int **matrice1, int **matrice2, int n, int p) {
  calculMatrice(1, matrice1, matrice2, n, p);
}

void soustractionMatrice(int **matrice1, int **matrice2, int n, int p) {
  calculMatrice(-1, matrice1, matrice2, n, p);
}

void produitMatrices(int **matrice1, int **matrice2, int n, int p) {
  printf("\n=============================================\n\n");
  printf("Produit des matrices : \n");
  int somme;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      somme = matrice1[i][j] * matrice2[i][j];
      printf("%d ", somme);
    }
    printf("\n");
  }
}

void transposeeMatrice(int **matrice, int n, int p) {
  printf("\n=============================================\n\n");
  printf("Transposee de matrice : \n");
  int **temp = genererMatrice(p, n);
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < n; j++) {
      temp[i][j] = matrice[j][i];
    }
  }
  afficherMatrice(temp, p, n);
  free(temp);
}

int main(void) {
  int lignes, colonnes;
  int **matrice1, **matrice2;

  printf("Lignes : ");
  scanf(" %d", &lignes);
  printf("Colonnes : ");
  scanf(" %d", &colonnes);

  matrice1 = genererMatrice(lignes, colonnes);
  saisirMatrice(matrice1, lignes, colonnes);
  afficherMatrice(matrice1, lignes, colonnes);
  // matrice2 = genererMatrice(lignes, colonnes);
  // saisirMatrice(matrice2, lignes, colonnes);
  // afficherMatrice(matrice2, lignes, colonnes);
  //
  // sommeMatrice(matrice1, matrice2, lignes, colonnes);
  // soustractionMatrice(matrice1, matrice2, lignes, colonnes);
  // produitMatrices(matrice1, matrice2, lignes, colonnes);
  transposeeMatrice(matrice1, lignes, colonnes);

  libererMatrice(matrice1, lignes);
  // libererMatrice(matrice2, lignes);

  return 0;
}
