#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include"ath.h"
using namespace std;

bool Read::open(ifstream& readFile, string filename){
    readFile.open(filename); // open the file name

    if(readFile.fail()){ // if the file fails to open, set openRead to false.
        cout<< "Could not open file." <<endl;

        return false;
    }
    else{ // set it true once the file is opened.
        return true;
    }
}

void Read::close(ifstream& readFile){
    readFile.clear(); // clear the read buffer.
    readFile.close(); // close the file from readUserInfo.
}

void Read::read(ifstream& read, string& bankName, string& account, string& name, string& socSec, string& pin, double& balance){
   string accountNo, userName, first, last, socialSec, pinNum, userBalance, empty; // these are 
                // place holder variables.

   getline(read, bankName, '\n'); // get the bank's name.

   read>> accountNo >> account; // read the account number
   read>> userName >> first >> last; // read the first and the last name
        name = first+" "+last; // concatenate the first and last name.
   read>> socialSec >> socSec; // read the social security number.
   read>> pinNum >> pin; // read the pin number (used for validation).
   read>> userBalance >> balance;

   read>>empty;
}

void Read::read(ifstream& read, string& bankName, string& account, string& name, string& socSec, string& pin, double& initBalance, double& currentBalance){
   string accountNo, userName, first, last, socialSec, pinNum, userBalance, curBal; // these are 
                // place holder variables.

   getline(read, bankName, '\n'); // get the bank's name.

   read>> accountNo >> account; // read the account number
   read>> userName >> first >> last; // read the first and the last name
        name = first+" "+last; // concatenate the first and last name.
   read>> socialSec >> socSec; // read the social security number.
   read>> pinNum >> pin; // read the pin number (used for validation).
   read>> userBalance >> initBalance;
   read>> curBal;
}


bool Write::open(ofstream& writeFile, string filename){
    writeFile.open(filename, ios::app); // open the same file and append to it.

    if(writeFile.fail()){
        cout<< "Could not open file." <<endl;

        return false;
    }
    else{
        return true;
    }
}

void Write::close(ofstream& writeFile){
    writeFile.clear(); //clear the write buffer.
    writeFile.close(); // close the file from writeUserInfo.
}

void Write::setHeader(ofstream& write){
    write<<"\nATH" << setw(15) << "TRANSACTION" <<setw(15)<< "AMMOUNT" <<setw(15)<< "BALANCE" <<setw(15)
         << "DATE" <<endl;
}

void Write::write(ofstream& write, double balance){
    write<< balance; 
}

void Write::write(ofstream& write, string transaction, string& time, double& ammount, double& currentBalance, unsigned& ath){
       write<< ath << setw(15) << transaction << setw(15) << ammount << setw(15) << currentBalance << setw(35) << time; 
}


double Transaction::depositCash(){
    double deposit;

    // ask the user how much they would like to deposit.
    cout<< "How much would you like to deposit?" <<endl;
        cin>> deposit;

    while(deposit-static_cast<int>(deposit)){
        cout<< "Only whole dollar ammounts are accepted, please reenter the "
            << "desired ammount: ";
            cin>> deposit;
    }

    // while the ammount entered is negative, prompt the user to reenter the
    // desired ammount.
    while(deposit < 0){
        cout<< "Invalid ammout. Please reenter ammount you would like to "
            << "deposit." <<endl;
            cin>> deposit;
    }

    return deposit;
}

double Transaction::depositCheck(){
    double deposit;

    cout<< "How much would you like to deposit? "
        << "(checks cannot exceed $5000.00)." <<endl;
        cin>> deposit;

    // if the ammount is negative or higher than $5000.00, reprompt the user.
    while(deposit < 0 || deposit > 5000){
        cout<< "Invalid ammout. Please reenter ammount you would like to "
            << "deposit." <<endl;
            cin>> deposit;
    }

    return deposit;
}

double Transaction::withdraw(double& bal){
    double withdrawal;

    // ask the user how much they would like to withdraw.
    cout<< "How much would you like to withdraw? "
        <<"(Please enter in multiples of 10);" <<endl;
        cin>> withdrawal;

    while(withdrawal-static_cast<int>(withdrawal)){
        cout<< "Only whole dollar ammounts are accepted, please reenter the "
            << "desired ammount: ";
            cin>> withdrawal;
    }

    // if the ammount entered is negative, not a multiple of 10 (when taking 
    // only the integer part), or makes the current balance negative, reprompt
    // the user to enter the desired ammount.
    while(withdrawal < 0 || static_cast<int>(withdrawal)%10 || bal-withdrawal <0){
        if(bal-withdrawal<0){ // if the balance goes under, tell the user
            cout<< "You do not have available funds." <<endl; // they do not 
                cin>> withdrawal; // have the available funds for the withdrawal.
        }
        else{
            cout<< "Invalid ammout, please enter in multiples of $10." <<endl;
                cin>> withdrawal;
        }
    }

    return withdrawal;
}

void Transaction::checkBal(double& bal){
    cout<< "Your current balance is: " << bal << "." <<endl;
}


