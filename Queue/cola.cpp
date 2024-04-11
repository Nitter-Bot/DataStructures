#include <iostream>
using namespace std;

class Nodo {
public:
    Nodo *siguiente;
    int valor;
    Nodo(int v, Nodo *sig = NULL) {
       valor = v;
       siguiente = sig;
    }
};

typedef Nodo *pnodo;

class Cola {
public:
   pnodo ultimo;
   pnodo primero;
   Cola(): ultimo(NULL), primero(NULL){}
   void push(int v);
   int pop();
};

void Cola::push(int v){
   pnodo nuevo;

   nuevo = new Nodo(v);
   
   if(ultimo) ultimo->siguiente = nuevo;

   ultimo = nuevo;
   if(!primero) primero = nuevo;
}

int Cola::pop(){
   pnodo nodo;
   int v;

   nodo = primero;
   if(!nodo) return 0;

   primero = nodo->siguiente;
   v = nodo->valor;
   delete nodo;
   if(!primero) ultimo = NULL;
   return v;
}

int main() {
   Cola cola;

   cola.push(20);
   cout << "Añadir(20)" << endl;
   cola.push(10);
   cout << "Añadir(10)" << endl;
   cout << "Leer: " << cola.pop() << endl;
   cola.push(40);
   cout << "Añadir(40)" << endl;
   cola.push(30);
   cout << "Añadir(30)" << endl;
   cout << "Leer: " << cola.pop() << endl;
   cout << "Leer: " << cola.pop() << endl;
   cola.push(90);
   cout << "Añadir(90)" << endl;
   cout << "Leer: " << cola.pop() << endl;
   cout << "Leer: " << cola.pop() << endl;

   return 0;
}
