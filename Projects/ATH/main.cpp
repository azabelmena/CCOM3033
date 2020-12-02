/*
An ATM Simulator.

This program simulates a rudamentary ATM machine for handling cash.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include"ath.h"
using namespace std;

int main(int argc, const char* argv[]){

//---------------- variables ------------------------------------------------
    time_t current = time(0); //get the system time.
    string currentTime = ctime(&current); //convert the system time into a
                                            //string.
    unsigned athNo = 100+rand()%500; // randomly generate an ATH number.

    Read inFile;
    Write outFile;

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

    inFile.open(readUserInfo, "userInfo.txt");

    inFile.read(readUserInfo, account.bankName, account.accNo, account.name, account.socSec, account.userPin, account.initBalance); // read the file data
                // into the appopriate variables.

    inFile.close(readUserInfo); // close the file from reading.
//---------------------------------------------------------------------------
//---------------- vaildate the pin, and open file for writing -----------------------------------------
    cout<< "Weclome to the " << account.bankName<< "." <<endl;

    Validation validatePin(account.userPin);

    outFile.open(writeUserInfo, "userInfo.txt");

    account.currentBalance = account.initBalance;

    outFile.setHeader(writeUserInfo);

//---------------------------------------------------------------------------
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

            outFile.write(writeUserInfo, "deposit", currentTime, userDeposit, account.currentBalance, athNo);

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

            outFile.write(writeUserInfo, "deposit", currentTime, userDeposit, account.currentBalance, athNo);
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

            outFile.write(writeUserInfo, "Withdrawal", currentTime, userWithdrawal, account.currentBalance, athNo);

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
            cout<< "Under Maintenence." <<endl; // Implement search here!!!
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
