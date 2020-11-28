/*
isPalindorme.cpp

A program that determines if a given word is a palindrome or not.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(const string&);

int main(){
    string palindrome;
    bool isPalin;

    cout<< "Enter a word: ";
        cin>> palindrome;

    isPalin = isPalindrome(palindrome);

    if(isPalin){
        cout<< palindrome << " is a palindrome." <<endl;
    }
    else{
        cout<< palindrome << " is a not palindrome." <<endl;
    }

    return 0;
}

bool isPalindrome(const string& str){
    int length = str.length()-1;

    for(int i = 0; i < length; i++){
        if(str[i] != str[length - i]){
            return false;
        }
    }
    return true;
}
