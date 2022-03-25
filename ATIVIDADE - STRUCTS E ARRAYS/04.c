#include <stdio.h>

typedef struct voluntarios{

float peso;
int idade;
float altura;
float IMC;

} VOLUNTARIOS;


void IMC(VOLUNTARIOS *voluntario , int quantiaDeVoluntarios) {
  int i;
  for(i = 0; i < quantiaDeVoluntarios; i++){

    voluntario[i].IMC = voluntario[i].peso/((voluntario[i].altura)*(voluntario[i].altura));

  }
  
}

float MediaIMC(VOLUNTARIOS *voluntario, int quantiaDeVoluntarios) {

  int i;
  float SomaIMC = 0;
  for(i = 0; i < quantiaDeVoluntarios; i++){

    SomaIMC = SomaIMC + voluntario[i].IMC;

  }

  return SomaIMC/quantiaDeVoluntarios;
}

int main() {

VOLUNTARIOS voluntario[2];

  voluntario[0].peso = 100;
  voluntario[0].altura = 1.90;

  voluntario[1].peso = 55.0;
  voluntario[1].altura = 1.50;
  
  IMC(voluntario, 2);
  printf("%.2f", voluntario[1].IMC);
  printf("\n%.2f", voluntario[0].IMC);


  float media = MediaIMC(voluntario, 2);

  printf("\n%.2f", media);
  return 0;
}