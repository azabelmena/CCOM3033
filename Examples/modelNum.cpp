#include<iostream>
using namespace std;

int main(){
    int model;

    cout<<"Our TVs come in three models:\n"
        <<"The modle 100, the model 200, or the model 300.\n"
        <<"Which model do you want? ";
            cin>>model;

    cout<<"Thst model has the following features:\n";

    switch(model){
        case 300: cout<<"Picture in a picture.\n";
        case 200: cout<<"Stereo sound.\n";
        case 100: cout<<"Remote control.\n";
            break;
        defualt: cout<<"You can only choose one of the three listed above."<<endl;
    }
    

    return 0;
}
