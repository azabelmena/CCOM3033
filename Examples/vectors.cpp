/*
vectors.cpp

A program that focuses on the implementation of the vector class in C++.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string palabra = "Saludos";
    char otraPalabra[] = "Saludos";
    char letra = 'r';

    for(int i = 0; i < palabra.length(); i++){
        cout<< palabra[i];
    }
    cout<<endl;

    string mediaPalabra = palabra.substr(0,palabra.length()/2);
    cout<< mediaPalabra <<endl;

    cout<< palabra.append(", buenas tardes!") <<endl;

    cout<< letra <<endl;
    letra=toupper(letra);
    cout<< letra <<endl;
    letra=tolower(letra);
    cout<< letra <<endl;

    cout<< isalpha(letra) <<endl;
    cout<< isdigit('2') <<endl;


    string num = to_string(500000000000000000);
    cout<< num+'8' <<endl;



    return 0;
}
