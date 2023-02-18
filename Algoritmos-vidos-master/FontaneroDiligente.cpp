/*La manera más eficiente de ordenar los servicios es de manera creciente, 
esto se puede comprobar corriendo el siguiente código algunas veces. 
Aparecerá el tiempo del servicio del cliente y su tiempo esperó*/

//Problema de la mochila aceptando solamente elementos enteros
#include<iostream>
#include<list>
#include <time.h>
#include<stdlib.h>
#include<iterator>
#include <bits/stdc++.h>

using namespace std;

struct Elemento{
    float tiempo;
    float espera;
};

void algoritmoAvido(Elemento e [], int numClientes, int tiempoTrabajo){
   
    list<Elemento> solucion;
    std:: list<Elemento>::iterator it;

    int tiempoActual=0, i = 0;
    cout<<"Orden de los servicios realizados: "<<endl;

    while(tiempoActual<tiempoTrabajo && i<numClientes){
        if(e[i].tiempo + tiempoActual <= tiempoTrabajo){
            solucion.push_back(e[i]);
            tiempoActual+= e[i].tiempo;
            //Actualización tiempos de espera de cada cliente
            if((i+1)<numClientes){
                e[i+1].espera = e[i].espera + e[i].tiempo;
            }
        }//End of if
        else{

        }
        ++i;
        
    }//End of while

    //Mostrar qué elementos se guardaron en la mochila 
    i = 0;
    for (it = solucion.begin(); it != solucion.end(); it++){ 
        cout<<"Cliente "<<i+1<<" con el tiempo de servicio: "<<it->tiempo<<", tiempo de espera: "<<it->espera<<endl;
        i++;   
    }


}//End of algoritmoAvido

int main(){
    //vars here
    int tiempoTrabajo = 0, numClientes=0, tiempoRequerido= 0, espera=0, maxTiempo=0;
    
    cout<<"Tiempo máximo de trabajo del fontanero: "<<endl;
    cin>>tiempoTrabajo;

    cout<<"Cantidad de clientes existentes: "<<endl;
    cin>>numClientes;

    cout<<"Máximo tiempo de servicios: "<<endl;
    cin>>maxTiempo;

    //Creando arreglo de elementos
    struct Elemento arr[numClientes];

    cout<<"Los tiempos requeridos por cada cliente son: "<<endl;
    //Creando elementos randomizados:
    srand(time(NULL));
    for(int i=0; i<numClientes; i++){
        tiempoRequerido = 1 + (rand()%maxTiempo);

        struct Elemento el = {(float)tiempoRequerido, 0.0};
        arr[i]= el;
        cout<<arr[i].tiempo<<" ";
    }//End of for

    cout<<"\n"<<endl;
    algoritmoAvido(arr, numClientes, tiempoTrabajo);
    return 0;

}//End of main