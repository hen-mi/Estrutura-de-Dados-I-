//lista é uma estrutura sem ordem 
#include <stdio.h>
#include <malloc.h>
typedef struct node{
int valor;
struct node* prox;
} NODE;

typedef struct {
NODE* inicio;
NODE* fim;
} LISTA;


void inserir(LISTA* lista, int valor);
void remover(LISTA* lista);
void copiaLista(LISTA* lista, LISTA* lista2); //copialista invertida como desafio

int main () {

  LISTA minhalista;
  minhalista.fim = NULL;
  minhalista.inicio = NULL;

  LISTA minhalista2;
  minhalista2.fim = NULL;
  minhalista2.inicio = NULL;
  
  inserir(&minhalista, 1);
  inserir(&minhalista, 2);
  inserir(&minhalista, 3);
  inserir(&minhalista, 2);
  inserir(&minhalista, 2);
  inserir(&minhalista, 2);
  inserir(&minhalista, 2);
  inserir(&minhalista, 785765656);
  

  NODE* aux = minhalista.inicio;
    printf("Minha lista\n");
  while(aux != NULL) {
    printf("%d\n", aux->valor);

    aux = aux->prox;
    
  }
  copiaLista(&minhalista, &minhalista2);
  remover(&minhalista2);
    NODE* aux2 = minhalista2.inicio;
    printf("Minha lista 2\n");
  while(aux2 != NULL) {
    printf("%d\n", aux2->valor);

    aux2 = aux2->prox;
    
  }

  return 0;
}

void inserir(LISTA* lista, int valor){
  //Inserir no fim
  NODE* novo = (NODE*) malloc(sizeof(NODE));
  novo->valor = valor;
  novo->prox = NULL;
  if(lista->inicio == NULL) {
      lista->inicio = novo;
      lista->fim = novo;
    
  } else {

    lista->fim->prox = novo;
    lista->fim = novo;
  } 
  
}

void remover(LISTA* lista) {
  NODE* apagar = lista->inicio;
  
  if(lista->inicio != NULL)
    lista->fim = NULL;
  
  lista->inicio = apagar->prox;
    free(apagar);
}

void copiaLista(LISTA* lista, LISTA* lista2) {

  NODE* aux = lista->inicio;

  while(aux != NULL) {
    
    inserir(lista2, aux->valor);
    aux = aux->prox;
    
  }
  
}