/*
priority.cpp

A program that sorts students based on their age, their assainged sex, and their
gpa. This is done using paralell arrays.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
using namespace std;

// this function will sort out applicants based on their priority. The 
// priority ranges from 0 to 3, and those with higher priority (i.e. 3, etc.)
// are placed first in the list.
void priority(int[], char[], double[], const int);

int main(){
    const int SIZE = 5; // set the array size to 5 for all arrays.

    int age[] = {19,21,23,24,26}; // the age array
    char sex[] = {'F','F','M','M','F'}; // the (presumed) sex array; (I use the presumed sex, for I do not want to make assumptions on gender identity).
    double gpa[] = {3.6, 3.5, 3.0, 3.7, 3.8}; // the gpa array.

    // display the table header of the applicants.
    cout<< "AGE" <<setw(8)<< "SEX" <<setw(7)<< "GPA" <<setw(15)<< "PRIORITY"<<endl;

    priority(age, sex, gpa, SIZE); // call the priority function.


    return 0;
}

void priority(int age[], char sex[], double gpa[], const int size){
    int priority[size]; // Declare the priortity accumulator array.

    for(int i = 0, i<size; i++){
        priority[i] = 0;
    }

    // here we accumulate the priority for each applicant. Each time a requisite
    // is fufulled, we add 1 to the priority for that applicant.
    for(int i = 0; i < size; i++){
        if(age[i] > 20 && age[i] < 26){ // if they are older than 20 but younger than 26.
            priority[i] += 1;           // add 1.
        }

        if(sex[i] == 'F'){ // If they are presumed female, add 1.
            priority[i] += 1;
        }

        if(gpa[i]>=3.5){ // if their GPA is 3.5 or above, add 1.
            priority[i] += 1;
        }
    }

    // sort the applicants in order of priority.
    for(int i = 0; i < size; i++){
        if(priority[i] < priority[i+1]){// if the priority of one applicant is
            swap(priority[i], priority[i+1]); // less than the priority of the
            swap(age[i], age[i+1]);         // next applicant, swap the places
            swap(sex[i], sex[i+1]);         // of the applicants (we also swap
            swap(gpa[i], gpa[i+1]);         // all other relavent information).
        }
    }

    // Display the applicants in order of priority. Those with the heighest
    // priority go first.
    for(int i = 0; i < size; i++){
        cout<< age[i]<<setw(8)<<sex[i]<<setw(8)<<setw(8)<< gpa[i]<<setw(8)<< priority[i] <<endl;
    }

}
