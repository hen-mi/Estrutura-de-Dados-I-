#include <stdio.h>

#define TAMANHO 20

char* copia(char *string, char *ondecopiar) {
  int i;
 for(i = 0; ondecopiar[i] != '\0'; i++) {
  ondecopiar[i] = string[i];
 }

return ondecopiar;
}

int main() {
 //teste
char a[] = "palavra";
  printf("%s\n", a);
char b[TAMANHO] = "copiar aqui";
  printf("%s\n", b);
  printf("%s\n", copia(a,b));
 

  return 0;
}
