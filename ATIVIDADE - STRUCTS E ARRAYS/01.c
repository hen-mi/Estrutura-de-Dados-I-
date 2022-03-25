#include <stdio.h>


float* SalLiquidos(float *salarios, int tamanho) {

  int i;
  
  for(i = 0; i <=  tamanho; i++){

    salarios[i] = salarios[i] - (salarios[i]*0.08);

  }
return salarios;
}


int main() {

float teste[]= {1050.22, 2022, 1020.15};
      printf("Bruto\n");
    for(int i = 0; i < 3; i++) {

            printf("%.2f\n", teste[i]);
      
    }
  SalLiquidos(teste, 3);

    printf("Líquido\n");
    for(int i = 0; i < 3; i++) {

            printf("%.2f\n", teste[i]);
      
    }

}