#include <stdio.h>
#include <string.h>
#define max(a, b) (a > b) ? a : b

void exo26(int tab[], int tab_length);
void exo27(void);
int exo27_recursif(int n);
void exo28(void);
void exo28_iterative(int n_termes);
void exo28_recursif(int n_termes);
void exo29(void);
void exo29_iterative(char tab[], int length);
void exo29_recursive(char tab[], int length, int n);
void exo30(void);
int saisir(char *chaine);

void exo26(int tab[], int tab_length) {
  int nb_max = tab[0];

  for(int i = 0; i < tab_length; i++) {
    nb_max = max(tab[i], nb_max);
  }

  printf("La plus grande valeur est : %d\n", nb_max);
}

void exo27(void) {
  // Ecrire une proc´edure r´ecursive qui prend un param`etre ´ n et qui teste si n contient au
  // moins un z´ero dans son ´ecriture en base 10. On fait ici la convention que l’´ecriture en base
  // 10 de z´ero est z´ero.
  int n, contient_zero;
  printf("Entrez le nombre svp : \n");
  scanf(" %d", &n);
  contient_zero = exo27_recursif(n);
  if (contient_zero) {
    printf("%d contient un zero", n);
  } else {
    printf("%d ne contient pas de zero", n);
  }
}

int exo27_recursif(int n) {
  if (n % 10 == 0) {
    return 1;
  } else if (n > 10) {
    return exo27_recursif(n / 10);
  } else {
    return 0;
  }
}

void exo28(void) {
  // La suite de Fibonacci une suite d’entiers dans laquelle chaque terme est la somme des
  // deux termes qui le pr´ec`edent : Un = Un−1 + Un−2. Elle commence avec les deux termes 0
  // et 1. Ainsi, les 7 premiers termes de cette suite sont : 0, 1, 1, 2, 3, 5, 8.
  //   — Ecrire la proc´edure it´erative qui permet de calculer le ´ neme terme de Fibonacci.
  //   — Ecrire la version r´ecursive de ce proc´edure. ´
  // Le r´esultat doit ˆetre sauvegard´e dans un param`etre de la proc´edure.
  int termes;
  printf("Combien de termes voulez-vous afficher ? ");
  scanf(" %d", &termes);
  printf("Par fonction recursive : \n\n");
  printf("Le terme 1 est 0\n");
  exo28_recursif(termes);
  printf("\nPar fonction iterative : \n\n");
  exo28_iterative(termes);
}

void exo28_iterative(int n_termes) {
  int a = 0, b = 1, Un, n = 1;

  printf("Le terme 1 est 0\n");
  for (int i = 1; i < n_termes; i++) {
    Un = a + b;
    a = b;
    b = Un;
    printf("Le terme %d est %d\n", i + 1, Un);
  }
}

void exo28_recursif(int n_termes) {
  static int a = 0, b = 1, n = 1;
  int Un = a + b;
  a = b;
  b = Un;
  printf("Le terme %d est %d\n", n + 1, Un);
  if (n_termes-1 > n) {
    n++;
    exo28_recursif(n_termes);
  }
}

void exo29(void) {
  // Un palindrome est un mot dont les lettres lues de gauche `a droite sont les mˆemes que
  // celles lues de droite `a gauche. Les mots radar, ´et´e, elle, ici sont des palindromes.
  //   — Ecrire la fonction it´erative qui permet de prendre un mot (une chaˆ ´ ıne de caract`eres)
  //   et r´epondre s’il s’agit d’un palindrome ou pas.
  //   — Ecrire la version r´ecursive de ce fonction.
  char chaine[64];
  int i = 0, chaine_length;
  printf("Entrez un mot : ");
  scanf(" %s", chaine);
  chaine_length = strlen(chaine);

  printf("Par fonction iterative : \n\n");
  exo29_iterative(chaine, chaine_length);
  printf("\nPar fonction recursive : \n\n");
  exo29_recursive(chaine, chaine_length, 0);
}

void exo29_iterative(char tab[], int length) {
  int palindrome = 1;
  for (int i = 0; i < length / 2; i++) {
    if (tab[i] != tab[length-1-i]) {
      palindrome = 0;
    }
  }
  if (palindrome) {
    printf("PALINDROME\n");
  } else {
    printf("PAS DU TOUT UN PALINDROME\n");
  }
}

void exo29_recursive(char tab[], int length, int n) {
  if (tab[n] == tab[length-1-n]) {
    if (n+1 > length / 2) {
      printf("PALINDROME\n");
    } else {
      exo29_recursive(tab, length, n+1);
    }
  } else {
    printf("PAS DU TOUT UN PALINDROME\n");
  }
}

void exo30(void) {
  // Ecrire une procédure récursive, prenant un caractère et une chaîne de caractères, qui
  // permet de donner dans un troisième paramètre le nombre d’occurrences du caractère dans
  // la chaîne
  char chaine[512], caractere;
  int chaine_longueur;
  longueur = saisir(chaine);
  scanf("%c", &caractere);
  printf("La chaine est \"%s\" et fait %d de longueur", chaine, longueur);
}

int saisir(char *chaine) {
  int i = 0;
  printf("Entrez une chaine de caractères :\n");
  scanf(" %c", &chaine[i]);
  while (chaine[i] != '\n') {
    i++;
    scanf("%c", &chaine[i]);
  }
  chaine[i] = '\0';
  return i;
}

int main(void) {
  int exercice;
  int tab[] = {1, 4, 5, 2, 32, 15 ,20, 6}, tab_length = 8;

  printf("Entrez le numero de l'exercice : ");
  scanf(" %d", &exercice);
  printf("\n======================================================\n\n");

  switch (exercice) {
    case 26:
      exo26(tab, tab_length);
      break;
    case 27:
      exo27();
      break;
    case 28:
      exo28();
      break;
    case 29:
      exo29();
      break;
    case 30:
      exo30();
      break;
    default:
      printf("Aucun exercice correspond a ce numero...\n");
      break;
  }

  return 0;
}
