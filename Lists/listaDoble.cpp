#include <iostream>

using namespace std;

class Nodo{
public:
   int dato;
   Nodo *siguiente;
   Nodo *anterior;
   Nodo(int dato,Nodo *sig=NULL,Nodo *ant=NULL):dato(dato),siguiente(sig),anterior(ant){}
};

typedef Nodo *pnodo;

class ListaDoble{
public:
   pnodo lista;
   ListaDoble():lista(NULL){}
   void push(int dato);
   void pop(int dato);
   void first();
   bool empty(){return lista==NULL;}
   void show(int o);
   void last();
};

void ListaDoble::first(){
   while(lista && lista->anterior)lista=lista->anterior;
}

void ListaDoble::last(){
   while(lista && lista->siguiente)lista=lista->siguiente;
}

void ListaDoble::push(int dato){
   pnodo nuevo;
   first();

   if( empty() || lista->dato > dato){
      nuevo = new Nodo(dato,lista);
      if(!lista)lista=nuevo;
      else lista->anterior=nuevo;
   }else{
      while (lista->siguiente && lista->siguiente->dato <= dato) {
         if(lista)lista=lista->siguiente;
      }

      nuevo = new Nodo(dato,lista->siguiente,lista);
      lista -> siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void ListaDoble::pop(int dato){
   pnodo aux;

   aux=lista;

   while(lista && lista->dato < dato)aux= aux->siguiente;
   while(lista && lista->dato > dato)aux=aux->anterior;

   if(!aux || aux->dato!=dato)return;

   if(aux->anterior)
      aux->anterior->siguiente = aux->siguiente;
   if(aux->siguiente)
      aux->siguiente->anterior = aux->anterior;
   delete aux;

}

void ListaDoble::show(int o){
   pnodo aux;

   if(o==1){
      first();
      aux=lista;
      while(aux){
         cout << aux->dato << "->" ;
         aux=aux->siguiente;
      }
   }else if(o==0){
      last();
      aux=lista;
      while(aux){
         cout << aux->dato << "->";
         aux=aux->anterior;
      }
   }
   cout<<endl;
}

int main(){
   cout<<"\n\t*** Linked List ***\n"<<endl;
   ListaDoble vector;
   vector.push(15);
   vector.push(10);
   vector.push(3);
   vector.push(78);
   vector.push(8);
   cout<<"Ascendente"<<endl;
   vector.show(1);
   cout<<"Descendente"<<endl;
   vector.show(0);
}
