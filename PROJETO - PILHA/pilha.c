#include <stdio.h>
#define TAMANHO_MAXIMO 10
  typedef struct {
    int id;
    int numerosDePaginas;
    float peso;
  } Documento;

typedef struct {
	Documento elementos[TAMANHO_MAXIMO];
	Documento* topo;
} PILHA;

void inicializarPilha(PILHA* pilha);
void limpaPilha(PILHA* pilha);
void imprimirPilha(PILHA* pilha);
void push(PILHA* pilha, int id, int numPag, float peso);
void pop(PILHA* pilha);
int length(PILHA* pilha);

int main () {
	PILHA minhaPilha;

	inicializarPilha(&minhaPilha);
	
	push(&minhaPilha, 2,44,1.6);
	push(&minhaPilha, 4,33,11);
	push(&minhaPilha, 6,1,1);

	imprimirPilha(&minhaPilha);

	pop(&minhaPilha);

	imprimirPilha(&minhaPilha);
	
	limpaPilha(&minhaPilha);
	
	imprimirPilha(&minhaPilha);	
}

void pop(PILHA* pilha){
  if(length(pilha) > 0) {
		pilha->topo->id = 0;
    pilha->topo->peso = 0;
    pilha->topo->numerosDePaginas = 0;
		pilha->topo -= 1;
  }
}

void push(PILHA* pilha, int id, int numPag, float peso) {
	if(length(pilha) < TAMANHO_MAXIMO) {
		pilha->topo += 1;
		pilha->topo->id = id;
    pilha->topo->peso = peso;
    pilha->topo->numerosDePaginas = numPag;
  }

}

void inicializarPilha(PILHA* pilha) {
  Documento *p;
  p = pilha->topo = &pilha->elementos[0];
  p--;
	pilha->topo = p;

}

void limpaPilha(PILHA* pilha) {
	pilha->topo = &pilha->elementos[0];
	pilha->topo -= 1;

}

int length(PILHA* pilha) {
  Documento *pAux;
  pAux = (&pilha->elementos[0]) - 1;
  
return pilha->topo - pAux;
}

void imprimirPilha(PILHA* pilha) {
	printf("PILHA :)\n");
	Documento *p;
  int auxsize;
  p = pilha->topo;
  auxsize = length(pilha);
	for( ; auxsize > 0; pilha->topo -= 1, auxsize--) {
    

		printf("|_%d_%d_%.2f_|\n", 
      pilha->topo->id,
      pilha->topo->numerosDePaginas,
      pilha->topo->peso
    );
	}	
  
	printf("\n\n");
  pilha->topo = p;

}