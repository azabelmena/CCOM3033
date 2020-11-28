/*
structs.cpp

A program that shows how structured data works in C++ (
class notes).

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

struct salud{
    string sangre;
};

struct personalInfo{
    string dirreccion;
    int telefono;
    string contacto;
    salud record;
};

struct Student{
    string name;
    int id;
    double gpa;
    int ingreso;
    personalInfo info;
};

int main(){
    Student gallito = {"Bob", 801161234, 3.5, 5}, jerezana; // Initialize gallito
                                                            // completely.
                                                            // and declare jerezana.
    jerezana.name = "Angela";  // initialize name to Angela.
    jerezana.gpa = 4.0; // initialize jerezana's gpa to 4.

    Student uprrp[4];

    for(int i = 0; i < 4; i++){
        uprrp[i].ingreso = 2018+i;
    }

    for(int i = 0; i < 4; i++){
        cout<< "El estudiante de la UPRRP N0. " << i+1 << "Entro al ano" 
            << uprrp[i].ingreso <<endl;
    }

    return 0;
}
