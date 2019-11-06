#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ComplexeCartesien {
  float reel;
  float complexe;
};

struct ComplexePolaire {
  float module;
  float argument;
};

struct Complexe {
  struct ComplexePolaire polaire;
  struct ComplexeCartesien cartesien;
};

struct ComplexePolaire convertirComplexeCartesien(struct ComplexeCartesien *c) {
  struct ComplexePolaire res;
  res.module = pow(pow(c->reel, 2) + pow(c->complexe, 2), 0.5);
  res.argument = atan(c->complexe / c->reel);
  return res;
}

struct ComplexeCartesien convertirComplexePolaire(struct ComplexePolaire *c) {
  struct ComplexeCartesien res;
  res.reel = c->module * cos(c->argument);
  res.complexe = c->module * sin(c->argument);
  return res;
}

void afficher(struct Complexe *a) {
  printf("Cartesien | reel = %f, complexe = %f\n", a->cartesien.reel, a->cartesien.complexe);
  printf("Polaire | module = %f, argument = %f\n", a->polaire.module, a->polaire.argument);
}

// struct Complexe sommeComplexe(struct Complexe a, struct Complexe b) {
//   struct Complexe res;
//   res.cartesien.reel = a.cartesien.reel + b.cartesien.reel;
//   res.cartesien.complexe = a.cartesien.complexe + b.cartesien.complexe;
//   res.polaire = convertirComplexeCartesien(&res.cartesien);
//   return res;
// }
//
// struct Complexe soustractionComplexe(struct Complexe a, struct Complexe b) {
//   struct Complexe res;
//
//   res.cartesien.reel = a.cartesien.reel - b.cartesien.reel;
//   res.cartesien.complexe = a.cartesien.complexe - b.cartesien.complexe;
//   res.polaire = convertirComplexeCartesien(&res.cartesien);
//
//   return res;
// }
//
// struct Complexe multiplierComplexe(struct Complexe a, struct Complexe b) {
//   struct Complexe res;
//
//   res.cartesien.reel = a.cartesien.reel * b.cartesien.reel - a.cartesien.complexe * b.cartesien.complexe;
//   res.cartesien.complexe = a.cartesien.reel * b.cartesien.complexe + a.cartesien.complexe * b.cartesien.reel;
//   res.polaire = convertirComplexeCartesien(res.cartesien);
//
//   return res;
// }
//
// struct Complexe diviserComplexe(struct Complexe a, struct Complexe b) {
//   struct Complexe res;
//
//   res.cartesien.reel = (a.cartesien.reel * b.cartesien.reel + a.cartesien.complexe * b.cartesien.complexe) / (pow(b.cartesien.reel, 2) + pow(b.cartesien.complexe, 2));
//   res.cartesien.complexe = (a.cartesien.reel * b.cartesien.reel + a.cartesien.complexe * b.cartesien.complexe) / (pow(b.cartesien.reel, 2) + pow(b.cartesien.complexe, 2));
//   res.polaire = convertirComplexeCartesien(res.cartesien);
//
//   return res;
// }
//
void resoudreEquation(struct Complexe a, struct Complexe b, struct Complexe c) {
  int delta = b^2 - 4 * a * c;
  int delta = multiplierComplexe(b, b)
}

int main(void) {
  struct Complexe a, b, c;
  struct Complexe *complexes[3] = {&a, &b, &c};
  char choix;

  printf("Resolution d'equation du second degre avec des complexes\n");
  printf("========================================================\n");

  for (int i = 0; i < 3; i++) {
    printf("\n> Entrer le complexe n %d\n", i+1);
    printf("Voulez-vous entrer le complexe en polaire ou cartesien ? (\"p\" ou \"c\") ");
    choix = 'a';
    while (choix != 'p' && choix != 'c') {
      scanf(" %c", &choix);
    }
    if (choix == 'p') {
      printf("Module = ");
      scanf(" %f", &(*complexes[i]).polaire.module);
      printf("Argument = ");
      scanf(" %f", &(*complexes[i]).polaire.argument);
      complexes[i]->cartesien = convertirComplexePolaire(&complexes[i]->polaire);
      afficher(complexes[i]);
    } else {
      printf("Reel = ");
      scanf(" %f", &(*complexes[i]).cartesien.reel);
      printf("Complexe = ");
      scanf(" %f", &(*complexes[i]).cartesien.complexe);
      complexes[i]->polaire = convertirComplexeCartesien(&complexes[i]->cartesien);
      afficher(complexes[i]);
    }
  }

  resoudreEquation(a, b, c);

  return 0;
}
