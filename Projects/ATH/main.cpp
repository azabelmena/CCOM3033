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
//#include"athFunc.h"
using namespace std;

struct AthInfo{
    string bankName;
    string accNo; 
    string name; 
    string socSec; 
    string pinFile;

    double initBalance;
    double currentBalance;

};
 
//--------- function declerations --------------------------------------------
bool openRead(ifstream&, string = "userInfo.txt"); //opens the ifstream object
            // and takes the user file as a default argument.
bool openWrite(ofstream&, string = "userInfo.txt"); //this is the same as 
            // openRead, but it opens the ofstream object

void closeRead(ifstream&); //close the file off from reading.
void closeWrite(ofstream&); // close the file off from writing.

void writeHeader(ofstream&, string&, string&, double&); // all this does is 
        //write the transaction header after a successful entry into the 
        //system.

void readInfo(ifstream&, string&, string&, string&, string&); // reads the 
        // information from the file into manageble variables.
double readBalance(ifstream&); // reads the balance from the file into a 
        // double variable.

bool validPin(string&); // validates the pin.
int menu(int); // a function to display the menu.

void writeTransaction(ofstream&, string, string&, double&, double&);

//The following are functions to deposit (in cash or in check), to withdraw, 
//and to check the balance.
double depositCash();
double depositCheck();
double withdrawal(double&);
void balanceCheck(double&);
//----------------------------------------------------------------------------

int main(){

//---------------- variables ------------------------------------------------

    time_t current = time(0); //get the system time.
    string currentTime = ctime(&current); //convert the system time into a
            //string.

    string bankName;
    string accNo, name, socSec, pinFile;

    double initBalance, currentBalance;

//---------------------------------------------------------------------------
//---------------- read the relavant info -----------------------------------
    ifstream readUserInfo; // the ifstream object.
    ofstream writeUserInfo; // the ofstream object.

    openRead(readUserInfo); //open the file for reading.

    getline(readUserInfo, bankName, '\n'); // get the bank's name.

    readInfo(readUserInfo, accNo, name, socSec, pinFile); // read the file data
                // into the appopriate variables.

    initBalance = readBalance(readUserInfo); // read the initial balance and
            // store it in a string.

    closeRead(readUserInfo); // close the file from reading.
//---------------------------------------------------------------------------
//---------------- vaildate the pin -----------------------------------------

    int attempts = 1; // the accumulator for the pin entry attempts

    cout<< "Welcome to the " << bankName << "." <<endl; // display the welcome 
            //messege.

    // these bool variables are to be used for validating the pin.
    bool check = false, validated = validPin(pinFile);

    if(!validated){ // if the pin is not validated display the following:
        while(attempts < 3){ //while attempts<3, prompt the user to 
                        // reenter their pin and inform them of their remaining
                        // attempts.
            cout<< "Invalid PIN. Please reenter your PIN (you have "
                << 3-attempts << " attempts remaining.)";

            validated = validPin(pinFile); // validate the pin again.

            if(!validated){ // if the validation again, add 1 to the attempts.
                attempts += 1;
            }
            else{ // if the pin is valid, set attempts to for to exit the while.
                attempts = 4;
            }

            if(attempts == 3){ //if the attempt accumulator reaches 3, promptly
                            // lock them out, and call the cops.
                cout<< "You have been locked out, we are calling the cops!" <<endl;
            }
        }
    }
    if(validated){ // if the pin is validated, do the following.
        openWrite(writeUserInfo); //open the file for writing, and write the 
                    // header of the transaction info.
        writeHeader(writeUserInfo, accNo, currentTime, initBalance);

        cout<< "Welcome " << name << "!\n"; // welcome the user.
        

//---------------------------------------------------------------------------
//-------------- ATH algorithm ----------------------------------------------

    int userChoice, choice, yesNo; //set the choices that the user will be making.

    double userDeposit, userWithdrawal, userCheck; // set the variables for the
                    // deposit, withdrawal, and the balance check.

    currentBalance = initBalance; // set the current balance to the initial balance.
    
    do{
        userChoice = menu(choice); //display the menu.

        if(userChoice == 1){ //this is the deposit choice
            int cashOrCheck; // another choice for the user to make.

            //prompt the user to enter wether they are depositing cash or check.
            cout<< "Enter 1 to deposit check, or enter 2 to deposit cash" <<endl;
                cin>> cashOrCheck;

            // if the choices aren't the ones displayed, reprompt the user.
            while(cashOrCheck != 1 && cashOrCheck != 2){
                cout<< "Enter 1 to deposit check, or enter 2 to deposit cash" <<endl;
                cin>> cashOrCheck;
            }

            if(cashOrCheck == 1){ // if the user chooses check
                userDeposit = depositCheck(); // depsoit the ammount 
                currentBalance += userDeposit; //add the deposit to the current
                                               // balance.
            }
            else{ // if the user chooses cash
                userDeposit = static_cast<int>(depositCash()); // deposit only 
                                               // the integer part (i.e. the paper bills)
                currentBalance += userDeposit; // add the deposit to the current balance.
            }

            // tell the user how much they have deposited, and ask if they would
            // like to make another transaction.
            cout<< "You have deposited $" << userDeposit << ".\n"
                << "Your current balance is $" << currentBalance << ". \n"
                << "Do you with to continue? Enter 0 to exit, or enter 1 "
                << "to continue." <<endl;
                cin>>  yesNo;

            // reprompt the user if they once again ignore what's on the screen.
            while(yesNo != 1 && yesNo != 0){
                cout<< "Please enter 0 to exit, or 1 to continue." <<endl;
                    cin>> yesNo;
            }

            // write the deposit info to the file.
            writeTransaction(writeUserInfo, "Deposit: " , currentTime, userDeposit, currentBalance);

            if(yesNo){ // if the user chose yes, set userChoice to -99 to
                userChoice = -99; // take them back to the menu.
            }
            else{ // if the user chose no, set userChoice to 0 and exit.
                cout<< "Exiting; have a nice day." <<endl;
                userChoice = 0; 
            }
        }
        else if(userChoice == 2){ // the withdraw choice.
            userWithdrawal = withdrawal(currentBalance); // stores the ammount
                            // withdrawn.
            
            //subtract the integer ammount from the current balance.
            currentBalance -= static_cast<int>(userWithdrawal);

            // tell the user how much they withdrew and ask them if they would
            // like to continue or not.
            cout<< "You have withdrawn $" << static_cast<int>(userWithdrawal) << ".\n"
                << "Your current balance is $" << currentBalance << ". \n"

                << "Do you with to continue? Enter 0 to exit, or enter 1 "
                << "to continue." <<endl;
                cin>>  yesNo;

            while(yesNo != 1 && yesNo != 0){
                cout<< "Please enter 0 to exit, or 1 to continue." <<endl;
                    cin>> yesNo;
            }

            // write the withdrawal info to the transaction reciept.
            writeTransaction(writeUserInfo, "Withdrawal:" , currentTime, userWithdrawal, currentBalance);

            if(yesNo){
                userChoice = -99;
            }
            else{
                cout<< "Exiting; have a nice day." <<endl;
                userChoice = 0;
            }


        }
        else if(userChoice == 3){ // the balance check choice.
                balanceCheck(currentBalance); // display the current balance.

                cout<< "Do you with to continue? Enter 0 to exit, or enter 1 "
                << "to continue." <<endl;
                cin>>  yesNo;

            while(yesNo != 1 && yesNo != 0){
                cout<< "Please enter 0 to exit, or 1 to continue." <<endl;
                    cin>> yesNo;
            }

            //write the balance check info to the transaction reciept.
            writeTransaction(writeUserInfo, "Balance Check:" , currentTime, currentBalance, currentBalance);

        if(yesNo){
                userChoice = -99;
            }
            else{
                cout<< "Exiting; have a nice day." <<endl;
                userChoice = 0;
            }

        }
        else{
            //if the user enters none of the menu options, prompt them to 
            // reenter one.
            if(userChoice != 0){
                cout<< "Please enter a valid menu option." <<endl;
            }
            else{ // if the user picks zero, exit the program.
                cout<< "Exiting; have a nice day." <<endl;
            }
        }
    }while(userChoice != 0);

}

//---------------------------------------------------------------------------

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

void writeHeader(ofstream& write, string& account, string& curTime, double& balance){
    unsigned athNo = 100+rand()%500; // randomly generate an ATH number.

    // write the header for the transaction reciept and format it.
    write<< "TRANSACTION" <<setw(15)<< "AMMOUNT" <<setw(15)<< "BALANCE" <<setw(15)
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

bool validPin(string& pinNum){ // validate the pin.
    string pinEntered; // the user's input pin.

    //prompt the user to enter their pin number.
    cout<< "Please enter your PIN: ";
        cin>> pinEntered; 

    if(pinEntered != pinNum){ //if the pin entered isn't equal to the one
                return false; // from the file, return false (i.e. not a valid pin).
    }
    else{ // if the pins match, return true.
        return true;
    }
}

int menu(int choice){ //display the menu and return the user's choice.
    cout<< "Press 0 to exit." <<endl;
    cout<< "Press 1 to deposit money." <<endl;
    cout<< "Press 2 to withdraw money." <<endl;
    cout<< "Press 3 to check your balance." <<endl;
        cin>> choice;

    return choice;
}

// this function writes the relevent transaction (i.e. deposit, withdrawal, or
// balance check) along with the accompanied information into the transaction
// reciept and formats it appropriately.
void writeTransaction(ofstream& write, string trans, string& curTime, double& transaction, double& curBal){
    write<< trans <<setw(15)<< transaction <<setw(15)
         << curBal <<setw(30)<< curTime <<endl;
}

double depositCash(){
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

// this is the same as above, except it works with checks.
double depositCheck(){
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

double withdrawal(double& bal){
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

void balanceCheck(double& bal){ //display the current balance.
    cout<< "Your current balance is: " << bal << "." <<endl;
}
//----------------------------------------------------------------------------
//---------- NOTES -----------------------------------------------------------
//
// The formatting is a little wonky due to generalizing the writing of the 
// transaction info into a function (I can no longer format each appropriatly),
// and as of now no there is no solution that comes to mind for this problem.
//
// An idea was had to have the user pick between cash or check again if they 
// entered a check deposit greater than $5000.00, however, all attempts at this
// have drawn infinite loops. A solution is being thought of.
//
//----------------------------------------------------------------------------
