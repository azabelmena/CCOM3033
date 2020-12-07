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

    Read inFile;  // declare the inFile and outFile objects 
    Write outFile; // for reading and writing.

    TransactionInfo transactionInfo; // declare the transactionInfo struct to store the transaction info.
    Search searchTransaction; // declare the searchTransaction class to bee able to use the 
                            // search functions.

    Account account; // declare the account struct to store the user data.
    Transaction transaction; // declare the transaction class to use the transaction functions.

    int userChoice, choice, yesNo; //set the choices that the user will be making.
    int cashOrCheck; // The user choice for if they wish to deposit cash or a check.
    
    double userDeposit, userWithdrawal, userCheck; // set the variables for the
                           // deposit, withdrawal, and the balance check.

    vector<TransactionInfo> transactions; // declare the vector that will hold the transaction info.
//---------------------------------------------------------------------------
//---------------- read the relavant info -----------------------------------
    ifstream readUserInfo; // the ifstream object.
    ofstream writeUserInfo; // the ofstream object.

    inFile.open(readUserInfo, argv[1]);

    inFile.read(readUserInfo, account); // read the file data
                // into the appopriate variables.
//---------------- vaildate the pin, and open file for writing -----------------------------------------
    // Print the welcome messege.
    cout<< "Weclome to the " << account.bankName<< "." <<endl;

    Validation validatePin(account.userPin); // invoke the Validation constructor.

    outFile.open(writeUserInfo, argv[1]);

    // read any existing transaction info into the transactions vector.
    transactions = inFile.read(readUserInfo,transactionInfo, transactions);

//-------------- ATH algorithm ----------------------------------------------
    // Welcome the user and prompt them to enter a menu option.
    cout<< "Welcome " << account.name << ". "
        << "Please enter one of the following:" <<endl;

    do{
        Menu displayMenu; // invoke the menu constructor.

        cin>> userChoice; // prompt the user to enter a choice.

        if(userChoice == 1){ // if the user enters 1

            // ask for check or cash.
            cout<< "Enter 1 to deposit in check or enter 2 to deposit in cash: ";
                cin>> cashOrCheck;

            // reprompt the user for anything other than 1 or 2.
            while(cashOrCheck != 1 && cashOrCheck != 2){
                cout<< "Enter 1 to deposit in check or enter 2 to deposit in cash: ";
                    cin>> cashOrCheck;
            }

            if(cashOrCheck == 1){ // if 1 is chosen:
                userDeposit = transaction.depositCheck(); // invoke depositCheck
                account.currentBalance += userDeposit; // add userDeposit to the currentBalance.
            }

            else{ // if the user chooses cash, do the same, invoke depositCash isntead.
                userDeposit = transaction.depositCash();
                account.currentBalance += userDeposit;
            }

            // store the deposit information.
            transactionInfo = {athNo, "Deposit", userDeposit, account.currentBalance, currentTime};
            transactions.push_back(transactionInfo); // puch the deposit information into the transactions vector.

            // print the user's transacted balance and aske them if they wish to continue.
            cout<< "You have deposited $"<< userDeposit <<" into your account. \n"
                << "Your current balance is: " << account.currentBalance << ".\n"
                << "Do you wish to continue? Enter 0 to exit or 1 to continue." <<endl;
                cin>> yesNo;

           while(yesNo != 0 && yesNo != 1){ // for choices other than 0 or 1, reprompt.
            cout<< "Enter 0 to exit or 1 to continue." <<endl;
                cin>> yesNo;
           }

           if(yesNo){ // if 1, display the menu and continue the program.
               displayMenu;
           }
           else{ // if 0, exit.
                cout<< "Exiting. Have a nice day!" <<endl;
                userChoice = 0;
           }
        }
        else if(userChoice == 2){ // If the user chooses 2
            // invioke the withdraw function and store it.
            userWithdrawal = transaction.withdraw(account.currentBalance);
            account.currentBalance -= userWithdrawal; // subtract userWithdrawal from the currentbalance.

            // store the transaction info.
            transactionInfo = {athNo, "Withdrawal", userWithdrawal, account.currentBalance, currentTime};
            transactions.push_back(transactionInfo); // push the transaction info.

            // display the ammount withdrawn and ask the user if they wish to continue.
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
        else if(userChoice == 3){ // if 3 is entered.
            transaction.checkBal(account.currentBalance); // print the current balance.

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
        else if(userChoice == 4){ // if 4 is chosen:
            // prompt the user for the search term.
            string searchTerm = searchTransaction.lookFor();
            vector<int> index; // declare the index.

            // search and print (if any) the corresponding transactions.
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
        else{ // if anything else is entered:
            if(userChoice){ // reprompt the user if it is not 0.
                cout<< "Please enter a valid menu option." <<endl;
            }
            else{ // exit if it is 0.
                cout<< "Exiting, have a nice day!" <<endl;
            }
        }
    }while(userChoice != 0); // Do while the choice is not 0.

    outFile.write(writeUserInfo, account); // write the user's account info.

    outFile.setHeader(writeUserInfo); // set the transaction header.
    outFile.write(writeUserInfo, transactions); // write the transaction info.

    outFile.close(writeUserInfo); // close the file from writing.
    inFile.close(readUserInfo); // close the file from reading.

    return 0;
}
