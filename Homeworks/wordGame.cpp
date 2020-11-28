/*
wordGame.cpp

A program that let's the user play a fun word game.

Created by: Alec Zabel-Mena.

*/
#include<iostream>
#include<string>
using namespace std;

int main(){

    // Declare the variables we will use for the word game.
    string name, age, city, college, profession, animal, pet;

    cout<< "Let's play a game!\n"<<endl; // A prompt to tell the user to play a game.


    // The following lines just as a series of questions in regards to their name, their age, a city, a college/university,
    // an animal, and their pets name (if they have one), or the name they would give a prospective pet.
    cout<< "What is your name? ";
       getline(cin,name); 

    cout<< "How old are you? ";
        cin>> age; 

    cout<< "Give me the name of a city: ";
        getline(cin, city); 

    cout<< "Give me the name of a college or university: ";
        getline(cin,college); 

    cout<< "Give me the name of a profession: ";
        getline(cin,profession); 

    cout<< "What is your favorite animal? ";
        getline(cin,animal); 

    cout<< "What would be the name of your pet? ";
        getline(cin,pet); 


    cout<<"\n"; // Seperates the output from the prompt.

    cout<<"There once was a person named "<< name << " who lived in " << city << ". At the age of \n"
        << age << ", " << name << " went to college at " << college << ". " << name << " graduated and went to work \n"
        << "as a " << profession << ". Then, " << name << " adopted a "<< animal << " named " << pet << ". They \n"
        << "lived happily ever after!" <<endl; // This is the end result of playing the word game.


    return 0;
}
