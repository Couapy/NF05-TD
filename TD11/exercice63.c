#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
  int valeur;
  struct Element *suivant;
} Pile;

void saisirPile(Pile **pile) {
  Pile *element;
  int nb;
  printf("Combien d'elements dans la pile ? ");
  scanf("%d", &nb);
  *pile = (Pile*)malloc(sizeof(Pile));
  element = *pile;
  for (int i = 1; i <= nb; i++) {
    if (i != 1) {
      element->suivant = (Pile*)malloc(sizeof(Pile));
      element = element->suivant;
      element->suivant = NULL;
    }
    printf("Valeur element n%d : ", nb-i+1);
    scanf("%d", &element->valeur);
  }
}

void afficherPile(Pile *pile) {
  Pile *element = pile;
  printf("=|-> ");
  while (element != NULL) {
    printf("%d -> ", element->valeur);
    element = element->suivant;
  }
  printf("NULL\n");
}

void empiler(Pile **pile, Pile *element) {
  element->suivant = *pile;
  *pile = element;
}

Pile* depiler(Pile **pile) {
  Pile *element = *pile;
  *pile = element->suivant;
  return element;
}

void circulation(Pile **pile, int nombre) {
  Pile *element = NULL, *premier = NULL, *aux = NULL; // ce sont des éléments
  Pile *inter = NULL; // C'est une pille
  if (*pile != NULL || (*pile)->suivant == NULL) {
    for (int i = 0; i < nombre; i++) {
      premier = depiler(pile);
      printf("PREMIER ! %d\n", premier->valeur);
      while (*pile != NULL) {
        aux = depiler(pile);
        empiler(&inter, aux);
      }
      empiler(pile, premier);
      while (inter != NULL) {
        empiler(pile, depiler(&inter));
      }

    }
  }
}

int main(void)  {
  Pile *pile;
  int nb;

  saisirPile(&pile);
  printf("Pile : ");
  afficherPile(pile);

  printf("Combien de fois voulez-vous circuler ? ");
  scanf("%d", &nb);
  circulation(&pile, nb);
  printf("Resultat : ");
  afficherPile(pile);

  printf("\n--= Fin du programme =--\n");

  return 0;
}
