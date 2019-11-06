#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Etudiant {
  char nom[24];
  char prenom[24];
  float median;
  float final;
  float moyenne;
};

struct Etudiant* saisirEtudiant(struct Etudiant *etu) {
  static int k = 0;
  k++;

  printf("============================================\n");
  printf("Saisie de l'etudiant n%d\n\n", k);

  printf("Nom : ");
  scanf(" %s", etu->nom);
  printf("Prenom : ");
  scanf(" %s", etu->prenom);
  printf("Median : ");
  scanf(" %f", &etu->median);
  printf("Final : ");
  scanf(" %f", &etu->final);
  etu->moyenne = (0.4 * etu->median + 0.6 * etu->final) / (0.4 + 0.6);
  printf("Moyenne : %.2f\n\n", etu->moyenne);

  return etu;
}

void trier(struct Etudiant *etus, int k) {
  int i, j, comparaison_nom, comparaison_prenom;
  struct Etudiant inter;
  for(i = 0; i < k-1; i++) {
    for(j = i+1; j < k; j++) {
      comparaison_nom = strcmp(etus[i].nom, etus[j].nom);
      comparaison_prenom = strcmp(etus[i].prenom, etus[j].prenom);
      if (comparaison_nom > 0 || (comparaison_nom == 0 && comparaison_prenom > 0)) {
        inter = etus[i];
        etus[i] = etus[j];
        etus[j] = inter;
      }
    }
  }

}

void afficher(struct Etudiant *etus, int n) {
  printf("============================================\n");
  printf("Affichage du tableau\n\n");
  for (int i = 0; i < n; i++) {
    printf("#%d %s %s\n", i+1, etus[i].nom, etus[i].prenom);
  }
  printf("\n");
}

int main(void) {
  int n;

  printf("Combien d'etudiants voulez-vous entrer ? ");
  scanf(" %d", &n);

  struct Etudiant *etus = malloc(n*sizeof(struct Etudiant));
  for (int i = 0; i < n; i++) {
    saisirEtudiant(etus+i);
  }

  afficher(etus, n);
  trier(etus, n);
  afficher(etus, n);

  free(etus);
  return 0;
}
