#include <stdio.h>
#include <stdlib.h>

struct Element {
  int entier;
  struct Element *suivant;
};

typedef struct {
  struct Element *premier;
  int nombre;
} Liste;

void insererElement(Liste *liste, struct Element *e) {
  printf("second : %d, premier : %d\n", liste->premier->entier, e->entier);
  e->suivant = liste->premier;
  liste->premier = e;
  liste->nombre++;
}

void supprimerElement(Liste *liste, struct Element *e) {
  if (e == liste->premier) {
    liste->premier = liste->premier->suivant;
    liste->nombre--;
  } else {
    struct Element *el = liste->premier;
    struct Element *precedant;
    for (int i = 0; i < liste->nombre; i++) {
      if (el == e) {
        precedant->suivant = el->suivant;
        liste->nombre--;
      }
      precedant = el;
      el = el->suivant;
    }
  }
}

void afficherListe(Liste *liste) {
  struct Element *element = liste->premier;
  printf("La liste contient : ");
  for (int i = 0; i < liste->nombre; i++) {
    printf("%d ", element->entier);
    element = element->suivant;
  }
  printf("\n");
}

struct Element* successeur(struct Element *e) {
  return e->suivant;
}

struct Element* predecesseur(Liste *liste, struct Element *e) {
  int i = 1;
  struct Element *el = liste->premier;
  for (int i = 0; i < liste->nombre; i++) {
    if (el->suivant == e) {
      return el;
    }
    el = el->suivant;
  }
  return e;
}

int main(void) {
  struct Element element1;
  struct Element element2;
  struct Element element3;
  element1.entier = 123;
  element2.entier = 456;
  element3.entier = 789;
  Liste liste = {&element3, 1};
  insererElement(&liste, &element2);
  insererElement(&liste, &element1);

  afficherListe(&liste);

  // printf("Premier element a pour valeur %d\n", predecesseur(&liste, &element2)->entier);
  // printf("Deuxieme element a pour valeur %d\n", successeur(&element1)->entier);
  // printf("Troisieme element a pour valeur %d\n", successeur(&element2)->entier);

  supprimerElement(&liste, &element2);
  afficherListe(&liste);

  return 0;
}
