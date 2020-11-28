/*
indexOfString.cpp

A program that finds the index of a character in a string, using sequential 
search.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<string>
using namespace std;

int indexOf(const string&, char);

int main(){
    string word;
    char value;

    cout<< "Enter a string of characters: ";
        cin>> word;

    cout<< "Which character would you like to search for? ";
        cin>> value;
        
     int position = indexOf(word, value);

    if(position == -1){
        cout<< "Value not found.";
    }
    else{
        cout<< value << " found at index " << position+1 << "." <<endl;
    }

    return 0;
}

int indexOf(const string& str, char ch){
    int position = -1, i = 0;
    
    while(i< str.length()){
        if(ch == str[i]){
            position = i;
        }
        i++;
    }

    return position;
}
