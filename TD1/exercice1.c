#include <stdio.h>
#include <time.h>

int main(void) {
  printf("Hello world !\n");
  printf("Nous sommes le Mercredi 18 Septembre 2019\n");
  printf("Et le numéro de la semaine actuelle est le 38\n");
  printf("Mon adresse E-Mail est : mael.marchand@utt.fr\n");
  time_t actTime;
  struct tm *timeComp;

  time(&actTime);
  timeComp = localtime(&actTime);
  /*creating string yyyy-MM-dd hh:mm:ss*/
  printf("%d-%02d-%02d %02d:%02d:%02d \n", timeComp->tm_year + 1900,
                                                     timeComp->tm_mon + 1,
                                                      timeComp->tm_mday,
                                                      timeComp->tm_hour,
                                                      timeComp->tm_min,
                                                      timeComp->tm_sec);
                                                      /*
   */
  return 0;
}
