/*
averageAray.cpp

A program that averages arrays.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int main(){
    const int ROW= 4, COL = 2;

    int notes[ROW][COL] = {{98,85}, {78,89},{92,95}};

    int sum = 0;
    int average;

    for(int j = 0; j < COL; j++){
        int i;
        for(i = 0; i < ROW-1; i++){
            sum += notes[i][j];
        }

        average = sum/(ROW-1);
        notes[i][j] = average;
    }

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cout<< notes[i][j]<< " ";
        }
    cout<<endl;
    }

    return 0;
}
