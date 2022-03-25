#include <stdio.h>

void troca(float *a, float *b) {

float temp = 0;

temp = *a;
*a = *b;
*b = temp;

}


int main() {

float a = 2, b = 4;
printf("a = %f\nb = %f\n", a, b);
troca(&a,&b);
printf("a = %f\nb = %f\n", a, b);

  return 0;
}