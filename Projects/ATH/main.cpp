/*
An ATM Simulator.
This program simulates a rudamentary ATM machine for handling cash.
Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include"ath.h"
using namespace std;

int main(int argc, const char* argv[]){

//---------------- variables ------------------------------------------------
    time_t current = time(0); //get the system time.
    string currentTime = ctime(&current); //convert the system time into a

    srand(current); // seed the random number generator for athNo.
                                            //string.
    unsigned athNo = 100+rand()%500; // randomly generate an ATH number.

    Read inFile;
    Write outFile;

    TransactionInfo transactionInfo;
    Search searchTransaction;

    Account account;
    Transaction transaction;

    int userChoice, choice, yesNo; //set the choices that the user will be making.
    int cashOrCheck; // The user choice for if they wish to deposit cash or a check.
    
    double userDeposit, userWithdrawal, userCheck; // set the variables for the
                           // deposit, withdrawal, and the balance check.

    vector<TransactionInfo> transactions;

//---------------------------------------------------------------------------
//---------------- read the relavant info -----------------------------------
    ifstream readUserInfo; // the ifstream object.
    ofstream writeUserInfo; // the ofstream object.

    inFile.open(readUserInfo, argv[1]);

    inFile.read(readUserInfo, account); // read the file data
                // into the appopriate variables.

//---------------- vaildate the pin, and open file for writing -----------------------------------------

    
    cout<< "Weclome to the " << account.bankName<< "." <<endl;

    Validation validatePin(account.userPin);

    outFile.open(writeUserInfo, argv[1]);

    transactions = inFile.read(readUserInfo,transactionInfo, transactions);

//-------------- ATH algorithm ----------------------------------------------
    cout<< "Welcome " << account.name << ". "
        << "Please enter one of the following:" <<endl;

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

            transactionInfo = {athNo, "Deposit", userDeposit, account.currentBalance, currentTime};
            transactions.push_back(transactionInfo);

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

            transactionInfo = {athNo, "Withdrawal", userWithdrawal, account.currentBalance, currentTime};
            transactions.push_back(transactionInfo);

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

            transactionInfo = {athNo, "Balance_Check", account.currentBalance, account.currentBalance, currentTime};
            transactions.push_back(transactionInfo);

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
        else if(userChoice == 4){
            string searchTerm = searchTransaction.lookFor();
            vector<int> index;

            searchTransaction.search(searchTerm, transactions, index);

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

    outFile.write(writeUserInfo, account);

    outFile.setHeader(writeUserInfo);
    outFile.write(writeUserInfo, transactions);

    outFile.close(writeUserInfo); // close the file from writing.
    inFile.close(readUserInfo); // close the file from reading.

    return 0;
}
