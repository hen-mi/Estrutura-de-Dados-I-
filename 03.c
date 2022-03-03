#include <stdio.h>

void copia(char *string, char *ondecopiar) {

 for(int i = 0; ondecopiar[i] != '\0'; i++) {
  ondecopiar[i] = string[i];

 }

}

int main() {
 //teste
char a[] = "palavra";
  printf("%s\n", a);
char b[20] = "copiar aqui";
  printf("%s\n", b);
copia(a,b);
  printf("%s\n", b);
  return 0;
}
