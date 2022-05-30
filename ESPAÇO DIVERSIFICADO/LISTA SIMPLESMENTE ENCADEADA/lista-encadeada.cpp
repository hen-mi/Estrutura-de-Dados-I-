#include <iostream>
#include "lista.h"
using namespace std;

int main() {

    Lista<string> teste;

    teste.inserirFinal("Super Mario Bros");
    teste.inserirFinal("The Legend of Zelda");
    teste.inserirInicio("Metroid");


    teste.mostrar();
    cout << endl;
    
    if(teste.existe("The Legend of Zelda"))
    cout << "The Legend of Zelda EXISTE!\n";

    teste.remover();
    teste.mostrar();
    cout << "Tamanho: " << teste.tamanho() << endl;

    
    if(teste.existe("The Legend of Zelda"))
    cout << "The Legend of Zelda EXISTE!";
    else{
        cout << "The Legend of Zelda NAO EXISTE!";
    }
    
    return 0;

}
