#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
  int valeur;
  int prioritee;
  struct Element *suivant;
} File;

void saisirFile(File **file) {
  File *element;
  int nb;
  printf("Combien d'elements dans la file ? ");
  scanf("%d", &nb);
  *file = (File*)malloc(sizeof(File));
  element = *file;
  for (int i = 1; i <= nb; i++) {
    if (i != 1) {
      element->suivant = (File*)malloc(sizeof(File));
      element = element->suivant;
      element->suivant = NULL;
    }
    printf("Valeur element n%d : ", nb-i+1);
    scanf("%d", &element->valeur);
    printf("Prioritee : ");
    scanf("%d", &element->prioritee);
  }
}

void afficherFile(File *file) {
  File *element = file;
  printf("=|-> ");
  while (element != NULL) {
    printf("%d -> ", element->valeur);
    element = element->suivant;
  }
  printf("NULL\n");
}

void emfiler(File **file, File *element) {
  File *e = *file;
  if (e == NULL) {
    *file = element;
  } else {
    while (e->suivant != NULL) {
      e = e->suivant;
    }
    e->suivant = element;
  }
  element->suivant = NULL;
}

File* defiler(File **file) {
  File *element = *file;
  *file = element->suivant;
  return element;
}

int main(void) {
  File *file = NULL, *copie = NULL;

  saisirFile(&file);
  copierFile(&file, &copie);

  printf("\n--= Fin du programme =--\n");

  return 0;
}
