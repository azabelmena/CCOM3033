/*
accountBalance.cpp

A program that asks the user what type of transaction they would like to search
for, and then displays all the relevent transactions for that search term.
(to be used for ath.cpp)

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

// function declerations.
string lookFor();
void readFile(ifstream&, vector<int>&, vector<string>&, vector<double>&, vector<double>&, vector<string>&);
void searchTransaction(string, vector<string>&, vector<int>&);
void printFound(vector<int>&, vector<int>&, vector<string>&, vector<double>&, vector<double>&, vector<string>&);

int main(){
    string transactionName; // declare a string to store user input.

    // declare the appropriate vectors.
    vector<int> athNo, index; // to store ATH numbers and vector incices.
    vector<string> transaction, date; // store transaction names, and dates.
    vector<double> ammount, balance; // store transactions and balances.

    ifstream readAccBal; // the read file object.
    
    readAccBal.open("accountBalance.txt"); // open accountBalance.txt

    if(readAccBal.fail()){// if the read.open fails, display the error messege.
        cout<< "Could not open file; make sure file exists." <<endl;

        return 0; // exit the program.
    }


    transactionName = lookFor(); // Ask the user for their desired transaction,
                                 // and store their input.

    string header; // a string to store the file's header.
    getline(readAccBal, header, '\n'); // get the file's header.

    //read the file, each data point to the appropriate vectors.
    readFile(readAccBal, athNo, transaction, ammount, balance, date);

    // search for the user's input within the transaction vector.
    searchTransaction(transactionName, transaction, index);

    cout<< header << endl;// print the header.

    //print the search results from searchTransaction, and the appropriate vector elements in
    // parallel.
    printFound(index, athNo, transaction, ammount, balance, date);

    return 0;
}

string lookFor(){
    string transactionName; // store the user's input.

    // ask the user which transaction they would like to look for.
    cout<< "What transaction would you like to look for?\n"
        << "Deposito\n" << "Retiro\n" << "Balance_Check\n";
        cin>> transactionName;


    // the following case handelling for the user input.
    if(transactionName == "deposito" || transactionName == "DEPOSITO"){
            transactionName = "Deposito";
    }

    if(transactionName == "retiro" || transactionName == "RETIRO"){
            transactionName = "Retiro";
    }

    if(transactionName == "balance_check" || transactionName == "BALANCE_CHECK"){
            transactionName = "Balance_Check";
    }

    // while the user enters anything other than the appropriate options, reprompt
    // the user.
    while(transactionName != "Deposito" && transactionName != "Retiro" && transactionName != "Balance_Check"){
        cout<< "Please enter one of the following transactions \n" 
            << "Deposito \n" << "Retiro\n" << "Balance_Check\n";
            cin >>transactionName;
    }

    return transactionName; // return the user input.
}
void readFile(ifstream& readFile, vector<int>& athNo, vector<string>& transaction, vector<double>& ammount, vector<double>& balance, vector<string>& date){ 
    int atm; //declare an atm variable.
    string trans, fecha; // declare transaction and date variables.
    double ammt, bal; // declare ammount and balance variables.

    // while the readFile is not at the end of the file:
   do{
       readFile>> atm >> trans >> ammt >> bal; // read into the variables
       getline(readFile, fecha, '\n'); // getline the date.

       //push the appropriate variables into the appropriate vectors to fill them.
       athNo.push_back(atm);
       transaction.push_back(trans);
       ammount.push_back(ammt);
       balance.push_back(bal);
       date.push_back(fecha);
   }while(readFile); 
}
// We implement the sequential search algorithm for searchTransaction.
void searchTransaction(string searchTerm, vector<string>& transaction, vector<int>& index){
    int first = 0, last = transaction.size()-1; // set the first and last indices.

    while(first <= last){ // while first <= last,
        if(searchTerm == transaction[first]){ //if the user input matches the 
            index.push_back(first); //vector element at index first, push first into the
        }                           // index vector.

        first++; // increment first.
    }
}
void printFound(vector<int>& index, vector<int>& athNo, vector<string>& transaction, vector<double>& ammount, vector<double>& balance, vector<string>& date){
    // For each index, print out the vector elements.
    for(int i = 0; i < index.size(); i++){
        cout<< athNo[index[i]]<< setw(15) << transaction[index[i]] << setw(20) 
            << ammount[index[i]] << setw(20) << balance[index[i]] << setw(22)
            << date[index[i]] <<endl;
    }
}
