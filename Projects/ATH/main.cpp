/*
template.cpp

Description

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include"ath.h"
using namespace std;


 
//--------- function declerations --------------------------------------------
bool openRead(ifstream&, string = "userInfo.txt"); //opens the ifstream object
            // and takes the user file as a default argument.
bool openWrite(ofstream&, string = "userInfo.txt"); //this is the same as 
            // openRead, but it opens the ofstream object

void closeRead(ifstream&); //close the file off from reading.
void closeWrite(ofstream&); // close the file off from writing.

void writeHeader(ofstream&); // all this does is 
        //write the transaction header after a successful entry into the 
        //system.

void readInfo(ifstream&, string&, string&, string&, string&); // reads the 
        // information from the file into manageble variables.
double readBalance(ifstream&); // reads the balance from the file into a 
        // double variable.

void writeTransaction(ofstream&, string, string&, double&, double&, unsigned);
//----------------------------------------------------------------------------

struct Account{
    string bankName;
    string accNo;
    string name;
    string socSec;
    string userPin;
    double initBalance;
    double currentBalance;
};

int main(int argc, const char* argv[]){

//---------------- variables ------------------------------------------------
    time_t current = time(0); //get the system time.
    string currentTime = ctime(&current); //convert the system time into a
                                            //string.
    unsigned athNo = 100+rand()%500; // randomly generate an ATH number.


    Account account;

    Transaction transaction;

    int userChoice, choice, yesNo; //set the choices that the user will be making.
    int cashOrCheck; // The user choice for if they wish to deposit cash or a check.
    
    double userDeposit, userWithdrawal, userCheck; // set the variables for the
                           // deposit, withdrawal, and the balance check.
                           //
    
//---------------------------------------------------------------------------
//---------------- read the relavant info -----------------------------------
    ifstream readUserInfo; // the ifstream object.
    ofstream writeUserInfo; // the ofstream object.

    openRead(readUserInfo); //open the file for reading.

    getline(readUserInfo, account.bankName, '\n'); // get the bank's name.

    readInfo(readUserInfo, account.accNo, account.name, account.socSec, account.userPin); // read the file data
                // into the appopriate variables.

    account.initBalance = readBalance(readUserInfo); // read the initial balance and
            // store it in a string.

    closeRead(readUserInfo); // close the file from reading.
//---------------------------------------------------------------------------
//---------------- vaildate the pin, and open file for writing -----------------------------------------

    cout<< "Weclome to the " << account.bankName<< "." <<endl;

    Validation validatePin(account.userPin);

    openWrite(writeUserInfo);

    account.currentBalance = account.initBalance;

    writeHeader(writeUserInfo);

//---------------------------------------------------------------------------
//-------------- ATH algorithm ----------------------------------------------


    do{
        Menu displayMenu;


        cin>> userChoice;

        if(userChoice == 1){
            cout<< "Enter 1 to deposit in check or enter 2 to deposit in cash: ";
                cin>> cashOrCheck;

            while(cashOrCheck != 1 && cashOrCheck != 2){
                cout<< "Enter 1 to deposit in check or enter 2 to deposit in cash: ";
                    cin>> cashOrCheck;
            }

            if(cashOrCheck == 1){
                userDeposit = transaction.depositCheck();
                account.currentBalance += userDeposit;
            }

            else{
                userDeposit = transaction.depositCash();
                account.currentBalance += userDeposit;
            }

            writeTransaction(writeUserInfo, "deposit", currentTime, userDeposit, account.currentBalance, athNo);

            cout<< "You have deposited $"<< userDeposit <<" into your account. \n"
                << "Your current balance is: " << account.currentBalance << ".\n"
                << "Do you wish to continue? Enter 0 to exit or 1 to continue." <<endl;
                cin>> yesNo;

           while(yesNo != 0 && yesNo != 1){
            cout<< "Enter 0 to exit or 1 to continue." <<endl;
                cin>> yesNo;
           }

           if(yesNo){
               displayMenu;
           }
           else{
                cout<< "Exiting. Have a nice day!" <<endl;
                userChoice = 0;
           }
        }
        else if(userChoice == 2){
            userWithdrawal = transaction.withdraw(account.currentBalance);
            account.currentBalance -= userWithdrawal;

            writeTransaction(writeUserInfo, "Withdrawal", currentTime, userWithdrawal, account.currentBalance, athNo);

            cout<< "You have withdrawn $"<< userWithdrawal <<" into your account. \n"
                << "Your current balance is: " << account.currentBalance << ".\n"
                << "Do you wish to continue? Enter 0 to exit or 1 to continue." <<endl;
                cin>> yesNo;

           while(yesNo != 0 && yesNo != 1){
            cout<< "Enter 0 to exit or 1 to continue." <<endl;
                cin>> yesNo;
           }

           if(yesNo){
               displayMenu;
           }
           else{
                cout<< "Exiting. Have a nice day!" <<endl;
                userChoice = 0;
           }
        }
        else if(userChoice == 3){
            transaction.checkBal(account.currentBalance);

            writeTransaction(writeUserInfo, "deposit", currentTime, userDeposit, account.currentBalance, athNo);

            cout<< "Do you wish to continue? Enter 0 to exit or 1 to continue." <<endl;
                cin>> yesNo;

           while(yesNo != 0 && yesNo != 1){
            cout<< "Enter 0 to exit or 1 to continue." <<endl;
                cin>> yesNo;
           }

           if(yesNo){
               displayMenu;
           }
           else{
                cout<< "Exiting. Have a nice day!" <<endl;
                userChoice = 0;
           }
        }
        else{
            if(userChoice){
                cout<< "Please enter a valid menu option." <<endl;
            }
            else{
                cout<< "Exiting, have a nice day!" <<endl;
            }
        }
    }while(userChoice != 0);

    return 0;
}

//---------- function definitions (in order of decleration) -----------------
bool openRead(ifstream& readFile, string filename){
    readFile.open(filename); // open the file name

    if(readFile.fail()){ // if the file fails to open, set openRead to false.
        cout<< "Could not open file." <<endl;

        return false;
    }
    else{ // set it true once the file is opened.
        return true;
    }
}

bool openWrite(ofstream& writeFile, string filename){
    writeFile.open(filename, ios::app); // open the same file and append to it.

    if(writeFile.fail()){
        cout<< "Could not open file." <<endl;

        return false;
    }
    else{
        return true;
    }
}

void closeRead(ifstream& readFile){
    readFile.clear(); // clear the read buffer.
    readFile.close(); // close the file from readUserInfo.
}

void closeWrite(ofstream& writeFile){
    writeFile.clear(); //clear the write buffer.
    writeFile.close(); // close the file from writeUserInfo.
}

void writeHeader(ofstream& write){

    // write the header for the transaction reciept and format it.
    write<<"ATH" << setw(15) << "TRANSACTION" <<setw(15)<< "AMMOUNT" <<setw(15)<< "BALANCE" <<setw(15)
         << "DATE" <<endl;
}

void readInfo(ifstream& read, string& account, string& name, string& socSec, string& pin){
   string accountNo, userName, first, last, socialSec, pinNum; // these are 
                // place holder variables.
   
   read>> accountNo >> account; // read the account number

   read>> userName >> first >> last; // read the first and the last name
        name = first+" "+last; // concatenate the first and last name.
   read>> socialSec >> socSec; // read the social security number.
   read>> pinNum >> pin; // read the pin number (used for validation).
}

// this function does the same as the previous, except it just reads the initial.
// balance.
double readBalance(ifstream& read){
    string userBalance;
    double initBalance;

    read>> userBalance >> initBalance; 

    return initBalance;
}

void writeTransaction(ofstream& write, string transaction, string& time, double& ammount, double& currentBalance, unsigned ath){
       write<< ath << setw(15) << transaction << setw(15) << ammount << setw(15) << currentBalance << setw(15) << time <<endl; 
}

//----------------------------------------------------------------------------
