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
  e->suivant = liste->premier;
  liste->premier = e;
  liste->nombre++;
}

struct Element* successeur(struct Element *e) {
  return e->suivant;
}

struct Element* predecesseur(Liste liste, struct Element e) {
  int i = 1;
  struct Element *temp = liste.premier;
  while (i <= liste.nombre && &e != temp->suivant) {
    temp = temp->suivant;
    i++;
  }
  return temp;
}

int main(void) {
  struct Element element1;
  element1.entier = 123;
  struct Element element2;
  element1.entier = 456;
  struct Element element3;
  element1.entier = 789;
  Liste liste = {&element3, 1};
  insererElement(&liste, &element2);
  insererElement(&liste, &element1);

  printf("Deuxieme element a pour valeur %d\n", predecesseur(liste, element2)->entier);

  printf("Done\n");

  return 0;
}
