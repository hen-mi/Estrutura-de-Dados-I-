#ifndef _LISTA_H
#define _LISTA_H_

using namespace std;

template<class T>

class NODE {

private:
    T valor;
    NODE<T>* prox;
public:
    NODE<T>(T valor) //construtor
    {
        this->valor = valor;
        this->prox = NULL;
    }   

    T getValor(){
        return this->valor;
    }
    NODE<T>* getNode(){
        return this->prox;
    }

    void setProx(NODE<T>* p) {
        this->prox = p;

    }
};

template<class T>
class Lista{
 private:   
    NODE<T>* inicio;
    NODE<T>* fim;
 public:
    Lista<T>(){
        inicio = NULL;
        fim = NULL;
    }
    Lista<T>(T valor) {
        inicio = new NODE<T>(valor);
        fim = inicio;
    }

    virtual ~Lista() {
        delete inicio;
    }

    bool vazia() {
        return (inicio == NULL);
    }
    void mostrar() {
        cout << "Imprimindo todos os elementos:\n";
        NODE<T>* pinicio = inicio;

        if(vazia()) {
            cout << "Sem elementos!\n";

        } else{
            while(pinicio) {
                cout << pinicio->getValor() << endl;
                pinicio = pinicio->getNode();
            }
        }
               
    }

    void inserirInicio(T valor) {

        NODE<T>* novoNode = new NODE<T>(valor);
        novoNode->setProx(inicio);
        inicio = novoNode;

    }
    void inserirFinal(T valor) {

        NODE<T>* novoNode = new NODE<T>(valor);
        if(vazia()) {
            inicio = novoNode;
            fim = novoNode;
        } else {
            fim->setProx(novoNode);
            fim = novoNode;
        }
    }

    int tamanho() {
        if(vazia())
            return 0;

            NODE<T>* pInicio = inicio;
            int tamanho = 0;

        do {
            pInicio = pInicio->getNode();
            tamanho++;

        } while(pInicio);        
      return tamanho;  
    }

    bool existe(T valor) {

        NODE<T>* pInicio = inicio;

        while(pInicio){
            if(pInicio->getValor() == valor)
            return true;

            pInicio = pInicio->getNode();
        } 
      return false;  
    }

    void remover() {
        if(!vazia())
         {
            //apenas um elemento
            if(inicio->getNode() == NULL)
                inicio = NULL;
            else if(inicio->getNode()->getNode() == NULL) //2 elementos
            {
                inicio->setProx(NULL);
            } else {

                NODE<T>* antepenultimo = inicio;
                NODE<T>* penultimo = inicio->getNode();
                NODE<T>* corrente = inicio->getNode()->getNode();

                while(corrente) {

                    NODE<T>* aux = penultimo;
                    penultimo = corrente;
                    antepenultimo = aux;
                    corrente = corrente->getNode();
                }
                delete antepenultimo->getNode();
                antepenultimo->setProx(NULL);
                fim = antepenultimo;

            }    

        }
    }
};

#endif