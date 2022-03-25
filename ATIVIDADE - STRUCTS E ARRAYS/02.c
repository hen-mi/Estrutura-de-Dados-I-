#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMANHO 50

typedef struct Paciente{

int idade;
char* profissao;
char* nome;
char* risco;  

} PACIENTE;


void prioridade(PACIENTE* paciente) {
  int i;
  char altorisco[5][MAX_TAMANHO] = {
  {"enfermeiro"},
  {"médico"},
  {"motorista"},
  {"motoboy"},
  {"atendente"}
  };

  
 paciente->risco = "desconhecido";
  if(paciente->idade > 60) {
    paciente->risco = "alto";
  }
  else{
    for(i = 0; i < 5; i++){

      if (strcmp(paciente->profissao, altorisco[i]) == 0) {

        paciente->risco = "alto";
      }
    }
  }
}

int main() {

  PACIENTE paciente1;
  paciente1.profissao = "teste";
  paciente1.idade = 60;

  PACIENTE paciente2;
  paciente2.profissao = "médico";
  
  PACIENTE paciente3;
  paciente3.idade = 62; 
  
  prioridade(&paciente1);
  prioridade(&paciente2);
  prioridade(&paciente3);
  
  printf("Risco do paciente 1: %s\n", paciente1.risco);
  printf("Risco do paciente 2: %s\n", paciente2.risco);
  printf("Risco do paciente 3: %s\n", paciente3.risco);
  
  return 0;
}