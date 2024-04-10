/*
RECREACION DE LAS TORRES DE HAMINOIL
*/
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

/*
    Creamos un nodo
    El constructor de la pila, al crearlo inicializamos el 
    ultimo nodo para que apunte a NULL
*/

class Pila{
public:
    pnodo ultimo;
    Pila():ultimo(NULL){}

    void push(int dato);
    int pop();
    void imprimir();
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

void Pila::imprimir(){
    pnodo nodo;
    int dato;
    
    if(!ultimo){
        cout <<" ";
        return;
    }
    nodo = ultimo;
    while(nodo){
        dato = nodo->dato;
        cout << dato << " ";
        nodo = nodo->siguiente;
    }
}

void torres(Pila *torre1,Pila *torre2,Pila *torre3){
    string s ="------------------\n";
    cout << s ;
    torre1->imprimir();
    cout <<"\t[1]\n"<< s;
    torre2->imprimir();
    cout <<"\t[2]\n"<< s ;
    torre3->imprimir();
    cout << "\t[3]\n"<<s;
}

int main(){
    cout << "\n\n\t*** Torres de haminoil ***\n"<<endl;

    Pila torre1,torre2,torre3;
    cout << "Con cuantos discos quieres jugar?" << endl;
    int n;
    cin >> n;
    for (int i = n-1; i >= 0; i--) {
        torre1.push(i+1);
    }
    while(true){
        torres(&torre1,&torre2,&torre3);
        short int a,b;
        int aux,aux1;
        cout << "\n\nDe que torre a q torre quieres mover [1~3]\n";
        cin >> a >> b;
        if(a==b){
            cout << "\nNo puedes elegir la misma torre"<<endl;
                   

        aux = torre3.pop();
        if(aux==n){
            break;
        }else{
            torre3.push(aux);
        }
    }
}
