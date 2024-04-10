#include <iostream>

using namespace std;

class Nodo{
public:
   int dato;
   Nodo *siguiente;
   Nodo(int dato,Nodo *sig=NULL):
      dato(dato),siguiente(sig){}
};

typedef Nodo *pnodo;

class Dequeu{
public:
   pnodo inicio;
   pnodo final;
   Dequeu():inicio(NULL),final(NULL){}
   void push_back(int v);
   void push_front(int v);
   int pop_back();
   int pop_front();
   bool empty();
   void show1();
   void show2();
};

bool Dequeu::empty(){
   return (inicio==NULL && final == NULL)? 1:0;
}

void Dequeu::push_back(int v){
   pnodo nuevo,aux;

   nuevo = new Nodo(v);
   if(final){
      final->siguiente = nuevo;

   }
   final = nuevo;
   if(!inicio){
      inicio=nuevo;
   }

}

void Dequeu::push_front(int v){
   pnodo nuevo,aux;

   nuevo = new Nodo(v);

   if(inicio){
      inicio->siguiente=nuevo;
   }
   inicio=nuevo;
   if(!final){
      final=nuevo;
   }

}

int Dequeu::pop_front(){
   pnodo aux;
   int v;

   aux = inicio;
   if(!aux)return 0;
   
   inicio = aux->siguiente;
   v = aux->dato;

   delete aux;

   if(!inicio)final=NULL;

   return v;
}

int Dequeu::pop_back(){
   pnodo aux;
   int v;

   aux = final;
   if(!aux)return 0;

   final=aux->siguiente;
   v = aux->dato;

   delete aux;

   if(!final)inicio=NULL;
   return v;
}

void Dequeu::show1(){
   while(!empty())
      cout<<pop_back()<<" ";
   
   cout<<endl;
}

void Dequeu::show2(){
   while(!empty())
      cout << pop_front()<<" ";
   cout << endl;
}

int main(){
   Dequeu cola,aux1,aux2;
   cout << "Cola doble\n"<<endl;
   cola.push_back(10);
   cola.push_front(23);
   cola.push_back(5);
   cola.push_front(16);
   
   aux1=cola;
   aux2=cola;
   cout<<"Pop back"<<endl;
   cout<<aux1.pop_back()<<endl;
   cout<<aux1.pop_back()<<endl;
   cout<<aux1.pop_back()<<endl;
   cout<<aux1.pop_back()<<endl;
   cout<<aux1.pop_back()<<endl;
}
