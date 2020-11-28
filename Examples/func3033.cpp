/*
gcd.cpp

Description

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int gcd(int, int);

int main(){

    cout<< gcd(5,1) <<endl;
    
    return 0;
}

int gcd(int a, int b){
    int r = a%b;

    while(r>0){
        a = b;
        b = r;
        r = a%b;
    }

    return b;
}

