/*
infoClases.cpp

Description

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<string>
using namespace std;

struct Clase{ // Create the clases struct
    int codigoClase; // with class code memeber
    string nombreClase; // and class name member
};

struct Nota{ // create the grade struct
    Clase infoClase; // with class info member
    double* notas = 0; // the notes pointer member.
    double promedio; // and average member
};

void showPtrStruct(Nota*);

int main(){
    Nota verano;

    showPtrStruct(&verano);

    return 0;
}
void showPtrStruct(Nota* punStruct){
    punStruct -> notas = new double[5]; // deferefence notes using punStruct.

    for(int i = 0; i < 5; i++){
        punStruct -> notas[i] = 90+i;

        cout<< *(punStruct -> notas+i) << "\t";
    }
    cout<<endl;
}
