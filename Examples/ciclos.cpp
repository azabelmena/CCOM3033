/*
ciclos.cpp

Ejemplo de ciclos en clase.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int main(){

    int cantNotas;
    double nota, average=0.0;

    cout<< "Dime cuantas notas tienes para esta clase: ";
        cin>> cantNotas;

    for(int i=0; i < cantNotas; i++){
        bool invalida = false;
       cout<<"Entre la nota numero" << i+1 << ": ";
            cin>> nota;

            if(nota<0 || nota>100 || !cin){
                cout<< "Nota invalida. Entra una nota: ";
                    cin>> nota;
                invalida = true;

            if(invalida){
                break; // forbidden.
            }

            }

        average += nota;
    }

    cout<< "El promedio de esta clase es: " << average/cantNotas <<endl;
    return 0;
}
