/*
pokemonCards.cpp

This program0 evaluates whether moira has 50 or less on a given test. If she has
50 or less on any given test, subtract half of her deck of 500 pokemon cards. If
she gets 100 on the last test, return all her cards to her.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int main(){
    const int CARDS = 500; // set the initial card lenght.
    int cards;
    double grade;

    cards = CARDS; // set cards to the initial 500.

    //prompt the user to enter their grades.
    cout<< "Enter your grades for each test (enter -99 to exit): ";

    do{
        cin>> grade;

        //if the user enters a negative number that is not the exit flag,
        // reprompt them.
        if(grade<0 && grade != -99){
           cout<< "Please enter positive grades: ";
                cin>> grade; 
        }

        if(grade <= 50 && grade >= 0){ // if grades are between 0 and 50
            cards /= 2;             // take half their cards.

            if(cards == 0){ // if they reach 0, exit.
                grade = -99;
            }

        }

        if(grade == 100){ //if they score 100, give them all their cards back.
            cards = CARDS;
        }

    }while(grade != -99);

    // display how many cards they have.
    cout<< "You now have " << cards << " cards." <<endl;

}
