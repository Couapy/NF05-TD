#include <stdio.h>

int main(void) {

  unsigned short A, B;
  float C;
  A = 104;
  C = 6.5;

  A += (unsigned short)C;
  A = ~A; //complément à 1
  B = A^(A+2);
  C = (float)(A<<B);
  A = A&(unsigned short)C;

  printf("A=%hu, B=%hu, C=%f", A, B, C);

  /**
   * Oui cela changerait car on a un type non signé, or int est signé, donc au minimum le signe changerait
   */

  return 0;
}
