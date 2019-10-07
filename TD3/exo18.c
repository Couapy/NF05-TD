#include <stdio.h>

int main()
{
    float s=1, splus=1.25;
    int i=1;

    while (splus - s >= 0.001)
    {
        i++;
        splus += 1.0/ ((i+1)*(i+1));
        s += 1.0 / (i*i);
    }
    printf("%d", i);
    return 0;
}
// La condition d'arret est >= epsilon
