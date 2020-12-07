/*
An ATM Simulator.

This program simulates a rudamentary ATM machine for handling cash.

Created by: Alec Zabel-Mena.
*/
#include<iostream> // include the appropriate header files.
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

    Read inFile; // declare the iFile struct for reading.
    Write outFile; // declare the outFile struct for writing.

    TransactionInfo transactionInfo; // declare the TransactionInfo struct for storing transaction infos.
    Search searchTransaction; // declare the search class so that the search functions can be used.

    Account account; // declare the account struct to stor the user's information.
    Transaction transaction; // declare the transaction class to be able to use the transaction functions.

    int userChoice, choice, yesNo; //set the choices that the user will be making.
    int cashOrCheck; // The user choice for if they wish to deposit cash or a check.
    
    double userDeposit, userWithdrawal, userCheck; // set the variables for the
                           // deposit, withdrawal, and the balance check.

    vector<TransactionInfo> transactions; // declare the vector of TransactionInfo.

//---------------------------------------------------------------------------
//---------------- read the relavant info -----------------------------------
    ifstream readUserInfo; // the ifstream object.
    ofstream writeUserInfo; // the ofstream object.

    inFile.open(readUserInfo, argv[1]); // Open the file for reading. argv[1] will be used in place of the file.

    inFile.read(readUserInfo, account); // read the file data
                // into the appopriate variables.

//---------------- vaildate the pin, and open file for writing -----------------------------------------

    
    cout<< "Weclome to the " << account.bankName<< "." <<endl; // welcome the user to the bank's atm.

    Validation validatePin(account.userPin); // invoke the validation constructor.
                // everything after this statement is only executed if the 
                // pin is validated.

    outFile.open(writeUserInfo, argv[1]); // open the file for writing.

    transactions = inFile.read(readUserInfo,transactionInfo, transactions); // store any 
                // transaction info in the file into the transactions vector.
//-------------- ATH algorithm ----------------------------------------------
    // Welcome the user, and promt them to enter the following.
    cout<< "Welcome " << account.name << ". "
        << "Please enter one of the following:" <<endl;

    do{
        Menu displayMenu; // invoke the menu constructor.

        cin>> userChoice; // prompt the user to enter their choice.

        if(userChoice == 1){ // if user enters 1:
            // ask if they would like to deposit cash or check.
            cout<< "Enter 1 to deposit in check or enter 2 to deposit in cash: ";
                cin>> cashOrCheck;

            // if the user enters anything other than 1 or 2, reprompt them.
            while(cashOrCheck != 1 && cashOrCheck != 2){
                cout<< "Enter 1 to deposit in check or enter 2 to deposit in cash: ";
                    cin>> cashOrCheck;
            }

            if(cashOrCheck == 1){ // if the user enter's one:
                userDeposit = transaction.depositCheck(); // invoke depositCheck() and store it in user deposit.
                account.currentBalance += userDeposit; // add userDeposit to the currentBalance.
            }
            else{ // if the user enters 2
                userDeposit = transaction.depositCash(); // do the same, but with depositCash().
                account.currentBalance += userDeposit;
            }

            // initialize transactionInfo to the user's deposit.
            transactionInfo = {athNo, "Deposit", userDeposit, account.currentBalance, currentTime};
            transactions.push_back(transactionInfo); // push transactionInfo into transactions.

            // display how much the user has deposited and ask them if they want to continue.
            cout<< "You have deposited $"<< userDeposit <<" into your account. \n"
                << "Your current balance is: " << account.currentBalance << ".\n"
                << "Do you wish to continue? Enter 0 to exit or 1 to continue." <<endl;
                cin>> yesNo;

            // while the user enters anything other than 0 or 1, reprompt them.
           while(yesNo != 0 && yesNo != 1){
            cout<< "Enter 0 to exit or 1 to continue." <<endl;
                cin>> yesNo;
           }

           if(yesNo){ // if the user enters 1, display the menu.
               displayMenu;
           }
           else{ // if the user enters 0, exit.
                cout<< "Exiting. Have a nice day!" <<endl;
                userChoice = 0;
           }
        }
        else if(userChoice == 2){// if the user chooses 2, 
            userWithdrawal = transaction.withdraw(account.currentBalance); // call withdraw() and store it in userWithdrawal.
            account.currentBalance -= userWithdrawal; // subtract user withdrawal from the currentBalance.

            //initialize the transactionInfo for the withdrawal.
            transactionInfo = {athNo, "Withdrawal", userWithdrawal, account.currentBalance, currentTime};
            transactions.push_back(transactionInfo); // push back into transactions.

            // display how much the user has withdrawn and ask them if they want to continue.
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
        else if(userChoice == 3){ // if the user enters 3
            transaction.checkBal(account.currentBalance); // call the checkBal function.

            // initialize transactionInfo to the balance check.
            transactionInfo = {athNo, "Balance_Check", account.currentBalance, account.currentBalance, currentTime};
            transactions.push_back(transactionInfo); // push back into transactions.

            // ask them if they want to continue.
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
        else if(userChoice == 4){ // if the user enters 4
            string searchTerm = searchTransaction.lookFor(); // invoke lookFor() and store it in searchTerm.
            vector<int> index; // declare the index vector.

            outFile.setHeader(); // set the header in the command line.
            searchTransaction.search(searchTerm, transactions, index); // search and display the transactions that 
                                    // match the search term.

            // ask if the user wants to continue.
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
    }while(userChoice != 0); // while the user's choice isn't 0.

    outFile.write(writeUserInfo, account); // rewrite the user's account information into the file.

    outFile.setHeader(writeUserInfo); // set the header.
    outFile.write(writeUserInfo, transactions); // write the transaction info into the file.

    outFile.close(writeUserInfo); // close the file from writing.
    inFile.close(readUserInfo); // close the file from reading.

    return 0;
}
