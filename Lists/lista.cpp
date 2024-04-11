#include <iostream>

using namespace std;

class Nodo{
public:
   int dato;
   Nodo *siguiente;
   Nodo(int dato, Nodo *sig=NULL):dato(dato),siguiente(sig){}
};

typedef Nodo *pnodo;

class Lista{
public:
   pnodo actual;
   pnodo primero;
   void push(int dato);
   void pop(int dato);
   Lista():primero(NULL),actual(NULL){}
   bool vacia(){return primero==NULL;}
   void imprimir();

};

void Lista::push(int v){
   pnodo anterior;

   if(vacia()|| primero->dato > v){
      primero = new Nodo(v,primero);
   }else{
      anterior = primero;

      while(anterior->siguiente && anterior->siguiente->dato <= v){
         anterior = anterior->siguiente;
      }

      anterior -> siguiente = new Nodo(v,anterior->siguiente);
   }
}

void Lista::pop(int v){
   pnodo nodo,anterior;
   
   nodo = primero;
   anterior = NULL;

   while(nodo && nodo->dato < v){
      anterior = nodo;
      nodo = nodo->siguiente;
   }
   
   if(!nodo || nodo->dato !=v)  return ;
   else{
      if(!anterior) primero = nodo->siguiente;
      else anterior->siguiente = nodo->siguiente;
      delete nodo;
   }
}

void Lista::imprimir(){
   pnodo aux;

   aux = primero;
   while(aux){
      cout << aux->dato << "->";
      aux = aux->siguiente;
   }

   cout << "\n";
}

int main(){
   Lista lista;

   lista.push(10);
   lista.push(5);
   lista.push(20);
   lista.push(5);
   
   lista.imprimir();// 5->5->10->20

   lista.pop(5);
   lista.imprimir();// 5->10->20

}




