//Problema de la mochila aceptando solamente elementos enteros
#include<iostream>
#include<list>
#include <time.h>
#include<stdlib.h>
#include<iterator>
#include <bits/stdc++.h>

using namespace std;

struct Elemento{
    float peso;
    int beneficio;
};

void algoritmoAvido(Elemento e [], int maxElem, float pesoMaxMochila){
   
    list<Elemento> solucion;
    std:: list<Elemento>::iterator it;

    int pesoActual=0, i = 0;
    cout<<"The backpack contains: "<<endl;

    while(pesoActual<pesoMaxMochila && i<maxElem){
        if(e[i].peso + pesoActual <= pesoMaxMochila){
            solucion.push_back(e[i]);
            pesoActual+= e[i].peso;
        }//End of if
        else{

        }
        ++i;
        
    }//End of while

    //Mostrar qué elementos se guardaron en la mochila
    i = 0;
    for (it = solucion.begin(); it != solucion.end(); it++){ 
        cout<<"Elemento "<<i+1<<" de la mochila con peso: "<<it->peso<<" y valor: "<<it->beneficio<<endl;
        i++;   
    }


}//End of algoritmoAvido

int main(){
    //vars here
    int pesoMax = 0, numElementos=0, miPeso= 0, miValor=0, pesoElem=0;
    
    cout<<"Peso máximo de la mochila: "<<endl;
    cin>>pesoMax;

    cout<<"Cantidad de elementos existentes: "<<endl;
    cin>>numElementos;

    cout<<"Máximo peso de elementos: "<<endl;
    cin>>pesoElem;

    //Creando arreglo de elementos
    struct Elemento arr[numElementos];

    cout<<"Los pesos de los elementos posibles son: "<<endl;
    //Creando elementos randomizados:
    srand(time(NULL));
    for(int i=0; i<numElementos; i++){
        miPeso = 1 + (rand()%pesoElem);
        miValor = 1 + (rand()%10);

        struct Elemento el = {(float)miPeso, miValor};
        arr[i]= el;
        cout<<arr[i].peso<<" ";
    }//End of for

    cout<<"\n"<<endl;
    algoritmoAvido(arr, numElementos, pesoMax);
    return 0;

}//End of main