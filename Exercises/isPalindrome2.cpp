/*
isPalindorme.cpp

A program that determines if a given word is a palindrome or not, using recursion.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

bool isPalindrome(const char[], int , int);

int main(){
    char palindrome1[] = "racecar", 
         palindrome2[] = "racecaR";
    bool isPalin;

    isPalin = isPalindrome(palindrome1, 0, 6);

    if(isPalin){
        cout<< palindrome1 << " is a palindrome." <<endl;
    }
    else{
        cout<< palindrome1 << " is a not palindrome." <<endl;
    }

    isPalin = isPalindrome(palindrome2, 0, 6);

    if(isPalin){
        cout<< palindrome2 << " is a palindrome." <<endl;
    }
    else{
        cout<< palindrome2 << " is a not palindrome." <<endl;
    }

    isPalin = isPalindrome(palindrome1, 6, 0);

    if(isPalin){
        cout<< palindrome1 << " is a palindrome." <<endl;
    }
    else{
        cout<< palindrome1 << " is a not palindrome." <<endl;
    }

    isPalin = isPalindrome(palindrome2, 6, 0);

    if(isPalin){
        cout<< palindrome2 << " is a palindrome." <<endl;
    }
    else{
        cout<< palindrome2 << " is a not palindrome." <<endl;
    }


    return 0;
}

bool isPalindrome(const char str[], int lower, int upper){
    if(str[lower] != str[upper]){
        return false;
    }
    else{
        return true;
    }

    if(lower < upper){
        isPalindrome(str, lower++, upper--);
    }
    else if(upper < lower){
        isPalindrome(str, lower--, upper++);
    }
}
