#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
  char nom[20];
  char prenom[100];
  int identifiant;
  char specialite[3];
  struct student * suivant;
} etudiant;

void saisirEtudiant(etudiant *etu) {
  printf("\n===============================================\n");
  printf("Nom : ");
  scanf(" %s", etu->nom);
  printf("Prenom : ");
  scanf(" %s", etu->prenom);
  printf("Identifiant : ");
  scanf(" %d", &etu->identifiant);
  while (strcmp(etu->specialite, "GSI") != 0 &&
  strcmp(etu->specialite, "GSM") != 0 &&
  strcmp(etu->specialite, "ISI") != 0) {
    printf("Specialite : ");
    scanf("%s", etu->specialite);
  }
}

etudiant* creerListe(int nbEtudiant) {
  etudiant *etu = (etudiant*)malloc(sizeof(etudiant)), *premier, *liste;
  premier = etu;

  for (int i = 0; i < nbEtudiant; i++) {
    saisirEtudiant(etu);
    if (i != nbEtudiant - 1) {
      etu->suivant = (etudiant*)malloc(sizeof(etudiant));
      etu = etu->suivant;
    } else {
      etu->suivant = NULL;
    }
  }

  return premier;
}

void afficherListe(etudiant *liste) {
  while (liste != NULL) {
    printf("\n  Nom : %s\n", liste->nom);
    printf("  Prenom : %s\n", liste->prenom);
    printf("  Identifiant : %d\n", liste->identifiant);
    printf("  Specialite : %s\n", liste->specialite);
    liste = liste->suivant;
  }
}

void trier(etudiant **liste, int nbEtudiant) {
  etudiant *premier = *liste, *etu, *precedent, *inter;
  int i, j = 0, comparaison_nom, comparaison_prenom;
  int continuer = 1;

  while (continuer) {
    continuer = 0;
    etu = premier;
    for (i = 0; i < nbEtudiant-j-1; i++) {
      comparaison_nom = strcmp(etu->nom, etu->suivant->nom);
      comparaison_prenom = strcmp(etu->prenom, etu->suivant->prenom);
      if (comparaison_nom > 0 || (comparaison_nom == 0 && comparaison_prenom > 0)) {
        continuer = 1;
        if (i != 0) {
          precedent->suivant = etu;
        } else {
          *liste = etu->suivant;
          premier = etu->suivant;
        }
        inter = etu->suivant->suivant;
        etu->suivant->suivant = etu;
        etu->suivant = inter;
      }
      precedent = etu;
      etu = etu->suivant;
    }
    j++;
  }
}

int identiques(etudiant *e1, etudiant *e2) {
  return strcmp(e1->nom, e2->nom) == 0 && strcmp(e1->prenom, e2->prenom) == 0 && e1->identifiant == e2->identifiant;
}

int insererEtudiant(etudiant **liste, etudiant *e) {
  // insérer un étudiant e dans la liste. La fonction retourne 1
  // si l’insertion est bien faite, 0 si un échec d’insertion est survenu.
  etudiant *etu = *liste;

  // Existe déjà
  while (etu != NULL) {
    if (identiques(etu, e)) {
      return 0;
    }
    etu = etu->suivant;
  }

  etu = *liste;
  int i = 0;
  while(1) {
    if (etu->suivant == NULL ||
      (strcmp(etu->nom, e->nom) > 0 ||
        (strcmp(etu->nom, e->nom) == 0 && strcmp(etu->prenom, e->prenom) > 0))) {
      e->suivant = etu->suivant;
      etu->suivant = e;
      if (i == 0) {
        *liste = e;
      }
      return 1;
    }

    etu = etu->suivant;
    i++;
  }
}


int main(void) {
  etudiant *liste, *etu_ajout = (etudiant*)malloc(sizeof(etudiant));
  int nb;

  printf("Combien y-a-t-il d'etudiants ? ");
  scanf("%d", &nb);

  liste = creerListe(nb);
  trier(&liste, nb);

  afficherListe(liste);

  saisirEtudiant(etu_ajout);
  insererEtudiant(&liste, etu_ajout);

  afficherListe(liste);

  // On free toute la liste
  int continuer = 1;
  etudiant *etu = liste, *suivant;
  while (continuer) {
    suivant = etu->suivant;
    free(etu);
    etu = suivant;
    if (etu->suivant == NULL) {
      continuer = 0;
    }
  }

  return 0;
}
