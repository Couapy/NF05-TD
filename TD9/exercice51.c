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
  static int nb = 0;
  nb++;
  printf("\n======================= n%d =======================\n", nb);
  printf("Nom : ");
  scanf(" %s", etu->nom);
  printf("Prenom : ");
  scanf(" %s", etu->prenom);
  // printf("Identifiant : ");
  // scanf(" %d", &etu->identifiant);
  // while (strcmp(etu->specialite, "GSI") != 0 &&
  // strcmp(etu->specialite, "GSM") != 0 &&
  // strcmp(etu->specialite, "ISI") != 0) {
  //   printf("Specialite : ");
  //   scanf("%s", etu->specialite);
  // }
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
    // printf("  Identifiant : %d\n", liste->identifiant);
    // printf("  Specialite : %s\n", liste->specialite);
    liste = liste->suivant;
  }
}

void trier(etudiant **liste) {
  etudiant *aux;
  etudiant *prec;
  etudiant *inter;
  int permutation;

  permutation = 0;
  while (permutation == 0) {
    permutation = 1;
    // il faut initialiser à l'intérieur de la boucle pour reprendre au début de la liste
    prec = NULL;
    aux = *liste;
    while(aux->suivant != NULL) {
      if (strcmp(aux->nom, aux->suivant->nom) > 0) {
        permutation = 0;
        if (aux == *liste) {
          *liste = aux->suivant;
          aux->suivant = aux->suivant->suivant;
          (*liste)->suivant = aux;

          prec = *liste;
          aux = prec->suivant;
        } else {
          inter = aux->suivant->suivant;
          aux->suivant->suivant = aux;
          prec->suivant = aux->suivant;
          aux->suivant = inter;

          prec = prec->suivant;
        }
      } else {
        if (prec == NULL) {
          prec = *liste;
          aux = prec->suivant;
        } else {
          prec = prec->suivant;
          aux = aux->suivant;
        }
      }
    }
  }
}

// void trier(etudiant **liste, int nbEtudiant) {
//   etudiant *premier = *liste, *etu, *precedent, *inter;
//   int i, j = 0, comparaison_nom, comparaison_prenom;
//   int continuer = 1;
//
//   // 3 Dupont Jean Doe John Calixte Axel
//
//   while (continuer) {
//     printf("\nTRI EN COURS\n");
//     afficherListe(*liste);
//     continuer = 0;
//     precedent = NULL;
//     etu = premier;
//     for (i = 0; i < nbEtudiant-j-1; i++) {
//       comparaison_nom = strcmp(etu->nom, etu->suivant->nom);
//       comparaison_prenom = strcmp(etu->prenom, etu->suivant->prenom);
//       if (comparaison_nom > 0 || (comparaison_nom == 0 && comparaison_prenom > 0)) {
//         printf("\nECHANGE %s <> %s\n", etu->nom, etu->suivant->nom);
//         continuer = 1;
//         if (precedent != NULL) {
//           precedent->suivant = etu->suivant;
//           etu = etu->suivant;
//         } else {
//           *liste = etu->suivant;
//         }
//         inter = etu->suivant->suivant;
//         etu->suivant->suivant = etu;
//         etu->suivant = inter;
//       } else {
//         if (precedent != NULL) {
//           precedent = precedent->suivant;
//           etu = etu->suivant;
//         } else {
//           precedent = *liste;
//           etu = precedent->suivant;
//         }
//       }
//     }
//     j++;
//   }
// }

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
      printf("\n\a[ERROR] L'etudiant existe deja\n");
      return 0;
    }
    etu = etu->suivant;
  }


  etu = *liste;

  if (strcmp(etu->nom, e->nom) > 0 ||
  (strcmp(etu->nom, e->nom) == 0 && strcmp(etu->prenom, e->prenom) > 0)) {
    *liste = e;
    e->suivant = etu;
    return 1;
  }

  while(1) {
    if (
      etu->suivant == NULL ||
      (strcmp(etu->nom, e->nom) < 0 && strcmp(etu->suivant->nom, e->nom) > 0) ||
      (strcmp(etu->nom, e->nom) == 0 && strcmp(etu->prenom, e->prenom) > 0)
    ) {
      e->suivant = etu->suivant;
      etu->suivant = e;
      return 1;
    }
    etu = etu->suivant;
  }
}

int supprimerEtudiant(etudiant **liste, etudiant *e) {
  etudiant *etu = *liste, *precedent = NULL;
  // 3 Dupont Jean Doe John Calixte Axel Carroy Manon

  while (etu != NULL) {
    if (identiques(etu, e)) {
      printf("TROUVE\n");
      if (precedent == NULL) {
        *liste = etu->suivant;
      } else {
        precedent->suivant = etu->suivant;
      }
      free(etu);
      return 1;
    }
    precedent = etu;
    etu = etu->suivant;
  }

  printf("[ERROR] L'etudiant n'existe pas...\n");
  return 0;
}

int main(void) {
  etudiant *liste, *etu_ajout = (etudiant*)malloc(sizeof(etudiant));
  int nb;

  printf("Combien y-a-t-il d'etudiants ? ");
  scanf("%d", &nb);

  liste = creerListe(nb);
  afficherListe(liste);

  trier(&liste);
  printf("\n[Tri fait !]\n");
  afficherListe(liste);

  saisirEtudiant(etu_ajout);
  insererEtudiant(&liste, etu_ajout);
  afficherListe(liste);

  printf("[ERROR] Il a obtenu trop de F\n[INFO] Nouvelle liste :\n");
  supprimerEtudiant(&liste, etu_ajout);
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
