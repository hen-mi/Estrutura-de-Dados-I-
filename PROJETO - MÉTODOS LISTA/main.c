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
void inserirPosicao(LISTA* lista, int valor, int posicao);
void remover(LISTA* lista);
void removerValor(LISTA* lista, int valor);
void removerAll(LISTA* lista, int valor);
void removerPosicao(LISTA* lista, int posicao);
NODE* buscar(LISTA* lista, int valor);
void limpar(LISTA* lista);
int tamanho(LISTA* lista);
void imprimir(LISTA* lista);
void copiaLista(LISTA* lista, LISTA* lista2);

int main () {

  LISTA minhalista;
  minhalista.fim = NULL;
  minhalista.inicio = NULL;

  LISTA minhalista2;
  minhalista2.fim = NULL;
  minhalista2.inicio = NULL;

  LISTA busca;
  busca.fim = NULL;
  busca.inicio = NULL;  
  inserir(&minhalista, 1);
  inserir(&minhalista, 2);
  inserir(&minhalista, 3);
  inserir(&minhalista, 2);
  inserir(&minhalista, 2);
  inserir(&minhalista, 2);
  inserir(&minhalista, 2);
  inserir(&minhalista, 785765656);
  inserirPosicao(&minhalista, 111, 8); //final
  inserirPosicao(&minhalista, 111, 5); //meio
  inserirPosicao(&minhalista, 111, 11); //ultrapassa = nao funciona 

  printf("---Lista 1---\n");
  imprimir(&minhalista);
  printf("tamanho: %d\n", tamanho(&minhalista));

  copiaLista(&minhalista, &minhalista2);
  remover(&minhalista2);
  removerPosicao(&minhalista2, 6); // remove do meio
  removerPosicao(&minhalista2, 7); //remove do final
  removerPosicao(&minhalista2, 0); //remove do comeco

  removerValor(&minhalista2, 3); 
  removerValor(&minhalista2, 2);
  printf("---Lista 2 (Copia de 1 com alteracoes)---\n");
  imprimir(&minhalista2);
  printf("tamanho: %d\n", tamanho(&minhalista2));
  removerAll(&minhalista2, 2);

  printf("---Lista 2 (Copia de 1 com alteracoes)---\n");
  imprimir(&minhalista2);
  printf("tamanho: %d\n", tamanho(&minhalista2));
  
  limpar(&minhalista);
  printf("---Lista 1---\n");
  imprimir(&minhalista);
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
  //apaga do inicio
  if(lista->inicio == NULL)
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

void imprimir(LISTA* lista) {
    NODE* aux = lista->inicio;
    
  while(aux != NULL) {
    printf("%d\n", aux->valor);

    aux = aux->prox;
    
  }
}

int tamanho(LISTA* lista) {
  int tamanho = 0;
  NODE* aux = lista->inicio;

  while(aux != NULL) {
    tamanho++;
    aux = aux->prox;
  }
  
  return tamanho;
  
}

NODE* buscar(LISTA* lista, int valor) {
   NODE* aux = lista->inicio;
    
  while(aux != NULL) {
    if(aux->valor == valor)
      return aux;
    aux = aux->prox;
  }

  return NULL;
}

void inserirPosicao(LISTA* lista, int valor, int posicao) {

  int auxp = 0;
  NODE* aux = lista->inicio;

 if(posicao <= tamanho(lista)) { 
   
    NODE* novo = (NODE*) malloc(sizeof(NODE));
    novo->valor = valor;
    novo->prox = NULL;
   
    if(posicao == 0){
      if(aux == NULL) {
        lista->inicio = novo;
        lista->fim = novo;

      }
      else if(aux != NULL){
        novo->prox = aux;
        lista->inicio = novo;
      
      }
      
    }
    else if(posicao == tamanho(lista)){
      inserir(lista, valor);
    }
    else if(posicao < tamanho(lista)) {
    
      while(aux != NULL && auxp <= posicao) {
      
        if(auxp == posicao-1) {
          
          novo->prox = aux->prox;
          aux->prox = novo;

        }
        auxp++;
        aux = aux->prox;
      }
    } 
  }   
}

void removerPosicao(LISTA* lista, int posicao) {
  
  NODE* apagar;
  NODE* aux = lista->inicio;
  int auxp = 0;

if(posicao <= tamanho(lista)-1) {
  if(posicao == 0) {
    remover(lista);
  }
  while(aux != NULL && auxp <= posicao) {
              
    if(auxp == posicao-1) {
      apagar = aux->prox;
        if(posicao == tamanho(lista)) {
          aux->prox = NULL;
          lista->fim = aux;
                    
        } else{
          aux->prox = aux->prox->prox;              
        }
       
        free(apagar);
        
      }
    auxp++;
    aux = aux->prox;
  }
}
}

void removerValor(LISTA* lista, int valor) {
  NODE* aux = lista->inicio;
  int index = 0;
  
   while(aux != NULL) {
     
    if(aux->valor == valor) {
      removerPosicao(lista, index);
      break;
    }

    aux = aux->prox;

    index++;
  }
}

void limpar(LISTA* lista) {
  NODE* aux = lista->inicio;
  NODE* apagar = aux;
  
  while(aux != NULL) {
    apagar = aux;
    aux = aux->prox;
    lista->inicio = aux;
    free(apagar);  
  }
  lista->fim = NULL;
}

void removerAll(LISTA* lista, int valor) {

  NODE* aux;
  while(buscar(lista, valor) != NULL) {
    
    aux = buscar(lista, valor);
    removerValor(lista, aux->valor);
    
  }
}