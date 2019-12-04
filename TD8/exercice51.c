#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  prete,
  disponible
} etatLivre;
typedef struct {
  int jour;
  int mois;
  int annee;
} date;
typedef struct {
  char auteur[20];
  char titre[100];
  char cote[9];
  int annee;
  char editeur[10];
  etatLivre EnPret;
  date DateDePret;
} BibLivres;

void saisirLivre(BibLivres *livre) {
  char reponse[10];
  printf("\n================================================\n");
  printf("Auteur : ");
  gets(livre->auteur);
  printf("Titre : ");
  gets(livre->titre);
  printf("Cote : ");
  gets(livre->cote);
  printf("Annee : ");
  scanf("%d", &livre->annee);
  getchar();
  printf("Editeur : ");
  gets(livre->editeur);
  printf("En pret : ('oui' ou 'non') ");
  gets(reponse);
  if (strcmp(reponse, "oui") == 0) {
    livre->EnPret = prete;
    printf("Date de pret :\n");
    printf("  > Jour : ");
    scanf(" %d", &livre->DateDePret.jour);
    getchar();
    printf("  > Mois : ");
    scanf(" %d", &livre->DateDePret.mois);
    getchar();
    printf("  > Annee : ");
    scanf(" %d", &livre->DateDePret.annee);
    getchar();
  } else {
    livre->EnPret = disponible;
    livre->DateDePret.jour = 0;
    livre->DateDePret.mois = 0;
    livre->DateDePret.annee = 0;
  }
}

void enregistrerLivre(FILE *fichier, BibLivres *livre) {
  fprintf(fichier, "%s\n", livre->auteur);
  fprintf(fichier, "%s\n", livre->titre);
  fprintf(fichier, "%s\n", livre->cote);
  fprintf(fichier, "%d\n", livre->annee);
  fprintf(fichier, "%s\n", livre->editeur);
  if (livre->EnPret == prete) {
    fprintf(fichier, "oui\n");
  } else {
    fprintf(fichier, "oui\n");
  }
  fprintf(fichier, "%d\n", livre->DateDePret.jour);
  fprintf(fichier, "%d\n", livre->DateDePret.mois);
  fprintf(fichier, "%d\n", livre->DateDePret.annee);
}

void stockerNLivres(int n) {
  BibLivres *livres = NULL;
  FILE *fichier;

  livres = (BibLivres*)malloc(n * sizeof(BibLivres));
  for (int i = 0; i < n; i++) {
    saisirLivre(&livres[i]);
  }

  fichier = fopen("files/exo51.txt", "w+");

  fprintf(fichier, "%d\n", n);
  for (int i = 0; i < n; i++) {
    enregistrerLivre(fichier, &livres[i]);
  }

  free(livres);
  fclose(fichier);
}

void rechercherLivre(void) {
  FILE *fichier;

  fichier = fopen("files/exo51.txt", "r");

  fclose(fichier);
}

int main(void) {
  int n;

  printf("Combien de livres voulez-vous entrez ? ");
  scanf(" %d", &n);
  getchar();

  stockerNLivres(n);

  rechercherLivre();

  return 0;
}
