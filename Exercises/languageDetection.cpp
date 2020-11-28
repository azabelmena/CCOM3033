/*
languageDetection.cpp

A program that detects what language the input is.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<string>
using namespace std;

int main(){

    string hello;
    do{
        cout<< "Enter the word hello in either English, Spanish, German,"
            <<" French, Italian, or Russian: ";
            cin>> hello;

        if(hello == "HELLO" || hello == "Hello" || hello == "hello"){
            cout<< "The language this is written in is English." <<endl;
        }
        else if(hello == "HOLA" || hello == "Hola" || hello == "hola"){
            cout<< "The language this is written in is Spanish." <<endl;
        } 
        else if(hello == "HALLO" || hello == "Hallo" || hello == "hallo"){
        cout<< "The language this is written in is German." <<endl;
        }
        else if(hello == "BONJOUR" || hello == "Bonjour" || hello == "bonjour"){
            cout<< "The language this is written in is French." <<endl;
        } 
        else if(hello == "CIAO" || hello == "Ciao" || hello == "ciao"){ 
            cout<< "The language this is written in is Italian." <<endl;
        }
        else if(hello == "ZDRAVSTVUJTE" || hello == "Zdravstvujte" || hello == "zdravstvujte"){
            cout<< "The language this is written in is Russian." <<endl;
        }
        else{
            cout<< "Unknown language." <<endl;
        }
    }while(hello != "#");

    return 0;
}
