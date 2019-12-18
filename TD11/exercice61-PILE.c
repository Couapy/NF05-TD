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

void copierPile(Pile **source, Pile **copie) {
  Pile *inter = NULL, *element = NULL;

  printf("Source : ");
  afficherPile(*source);

  while (*source != NULL) {
    empiler(&inter, depiler(source));
  }
  printf("Inter : ");
  afficherPile(inter);

  while (inter != NULL) {
    element = depiler(&inter);
    empiler(source, element);
    empiler(copie, element);
  }
  printf("Copie : ");
  afficherPile(*copie);
}

int main(void) {
  Pile *pile = NULL, *copie = NULL;

  saisirPile(&pile);
  copierPile(&pile, &copie);

  printf("\n--= Fin du programme =--\n");

  return 0;
}
