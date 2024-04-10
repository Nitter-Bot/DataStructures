#include <iostream>
#include <string>

using namespace std;

/* Nodo general de una pila

    Se componen solamente del dato que almacenan y un apuntador al
    dato siguiente
    new   ->   dato->dato->dato->NULL
    Ultimo en entrar            Primer dato
*/

class Nodo{
public:
    Nodo(){}
    Nodo(int dato, Nodo *sig=NULL):dato(dato),siguiente(sig){}
    int dato;
    Nodo *siguiente;
};

//Solo ocupamos esta notacion
typedef Nodo *pnodo;

/*  Clase PILA
ATRIBUTOS
    Creamos un nodo que sera el ultimo dato ingresado
    El constructor de la pila, al crearlo inicializamos el 
    ultimo nodo para que apunte a NULL
METODOS 
    push, empujamos un elemento nuevo a la pila
    pop, eliminamos el primer elemento de la pila
*/

class Pila{
public:
    pnodo ultimo;
    Pila():ultimo(NULL){}

    void push(int dato);
    int pop();
};

void Pila::push(int dato){
    pnodo nuevo;
    nuevo = new Nodo(dato,ultimo);

    ultimo = nuevo;
}

int Pila::pop(){
    pnodo nodo;
    int dato;
    if(!ultimo)return 0;
    nodo = ultimo;
    dato = nodo->dato;
    ultimo = nodo->siguiente;
    delete nodo;
    return dato;
}

int main(){
    cout << "\n\n\t*** Pilas ***\n"<<endl;
    cout << "Demostracion basica del uso de la estructura\n"<<endl;
    
    Pila pila;
    pila.push(5);
    cout <<"Push 5"<<endl;
    pila.push(7);
    cout << "Push 7" << endl;
    pila.push(9);
    cout << "Push 9" << endl;
    cout << "Pop -> "<<pila.pop()<<endl;
    pila.push(11);
    cout << "Push 11"<<endl;
    cout << "Pop ->"<<pila.pop()<<endl;
    cout << "Pop ->"<<pila.pop()<<endl;
    cout << "Pop ->"<<pila.pop()<<endl;
    
}
