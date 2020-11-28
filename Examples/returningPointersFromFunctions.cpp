/*
returningPointersFromFunctions.cpp

A program that shows how to return pointers from functions.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int* getRandomNumbers(int);

int main(){
    int num;
    int* numbers = 0;

    cout<< "Enter an integer: ";
        cin>> num;

    numbers = getRandomNumbers(num);

    for(int i = 0; i < num; i++){
        cout<< numbers[i] <<endl;
    }

    delete [] numbers; // Free the memory.
    numbers = 0; // Set numbers to the nullptr.

    return 0;
}

int* getRandomNumbers(int num){
    int* array = 0; // This is the array we will be working with.

    if(num <= 0){ // If num is nonpositive, return the 0 memory address.
        return 0;
    }

    array = new int[num]; // Dynamically allocate memory to array.

    srand(time(0)); // seed the random variable.

    for(int i = 0; i < num; i++){
        array[i] = rand(); // Populate the array with random numbers.
    }

    return array; // Return the pointer to the array.
}

/*
Remark:

In getRandomNumbers, we dynamically allocate memory to array. Under normal circumsatances, 
it is a common mistake to return the pointer, even theough the variable it points to no longer 
exists (as variables defined in functions do not leave the scope of the function). However, we bypass this by 
dynamically allocating memmory, without deleting it within the function, which allow the memeory to stay allocated 
even after the function terminate. This will allow us to return array without problem.

Another good strategy is to pass the variable you want to point to as an argument in the function, so that 
when you return it's pointer, the memory it points to still exists.
*/
