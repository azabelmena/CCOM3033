/*

averageScores.cpp   

A Program to average test scores.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    
    const double highScore = 95; // A 95 or above is considered a high score.
    const double perfectScore = 100; // a 100 is considered a perfect score.

    double score1, score2, score3, average; // holds three scores and the average between them.

    cout<< "Enter 3 test scores: "; // Get the test scores.
        cin>> score1 >> score2 >> score3;

    average = (score1+score2+score3)/3; // Average the score.

    cout<< fixed << showpoint << setprecision(2); // Format the output
    cout<< "Your average for the three tests is: " << average <<endl; //display the average.

    if(average >= highScore && average < perfectScore){
        cout<< "You have a high score." <<endl;
    }
    
    else if(average == perfectScore){
        cout<< "You have a perfect score." <<endl;
    }
    else if(average < 0){
        cout<< "Did you input the scores correctly?\n"
            << "Please reload the program.\n"
            <<"Exit code: 1" <<endl;
    } 
}
