#include <stdio.h>

void MaiorMenor(int *vet, int tamVet, int *a, int *b) {

int menor = 0, maior = 0;
int i;
for(i = 0; i <= tamVet; i++) {

if(i == 0) {
menor = vet[i];
maior = vet[i];

}
if(vet[i] < menor)
menor = vet[i];

else if(vet[i] > maior) {

maior = vet[i];
} 

}

*a = menor;

*b = maior;

}

int main() {
//Situação teste
int vet[5] = {5,55,3,2,-1}, a = 0, b = 0;

MaiorMenor(vet, 5, &a, &b);

printf("menor = %d\nmaior = %d\n", a, b);


  return 0;
}