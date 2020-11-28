/*
ath.cpp

This program simulates an ATH machine, asking the user for their PIN number, 
and then displaying a menu for the type of transaction they wish to perform.
After the transaction is done, the transaction information is written to a file
presumed to be ``printed'' by the ATH.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
//--------------- variables -------------------------------------------------
    time_t current = time(0); // get the current system time
    string currentTime = ctime(&current); // display the current time in 
                        // string format.

    unsigned athNo = 100+rand()%500; //Used for generating a random ATM machine no.
    int receipt, yesNo, choice = -99, attempts = 1; // set the attempts variable 
                //to 1 attempt (since the initial entering of the PIN counts as 
                //an attempt).

    // string variables to store the relevent data from the file, there are
    // some extraneous variables to make data managment easier.
    string account, userName, socialSec, pinNum, userBalance;
    string bankName, firstName, lastName, accNo, socSec;

    string pinFile, pinUser; //string variables to store the users pin number
                         // and the pin number entered by the user.
    int withdrawal; //stores the amount of money to withdraw (int cause it is in
                    // multiples of $10.
    double initBalance, deposit, currentBalance; //double variables to stor the
            // initial balance, the deposit, and the current balance.
//---------------------------------------------------------------------------
//------ Open file for reading and writing ----------------------------------
    ifstream readUserInfo; //create the readFile object.

    readUserInfo.open("userInfo.txt"); //open userInfo.txt for readinh=g.

    if(readUserInfo.fail()){ //If userInfo.txt cannot be opened, display an 
        cout<< "Could not read banking information." <<endl; //error messege.
    }

    ofstream writeTransInfo, writeUserInfo; //create the writeFile object.

    writeTransInfo.open("ath3033.txt", ios::app); //open reciept.txt for writing.

    if(writeTransInfo.fail()){ //if reciept.txt could not be opened, display an
        cout<< "Could not write to transaction reciept." <<endl; //error messege.
    }
//----------------------------------------------------------------------------
//------ Get data from the file ----------------------------------------------
    getline(readUserInfo, bankName, '\n'); //get the bank's name

    readUserInfo>> account >> accNo; //get the account number.
    readUserInfo>> userName >> firstName >> lastName; //get first and last names.
    readUserInfo>> socialSec >> socSec; //get the social security number
    readUserInfo>> pinNum >> pinFile; //get the user's pin number.
    readUserInfo>> userBalance >> initBalance; //get the user's initial balance.
//----------------------------------------------------------------------------
    readUserInfo.clear(); //clear the read buffer.
    readUserInfo.close(); //close userInfo.txt from reading. 

//------ ATH algorithm -------------------------------------------------------

    writeTransInfo<<setprecision(15); //set the precision to 15 minutes.

    currentBalance = initBalance; //sets the current balance of the user to 
            // the initial balance found in the file.

    //Display the welcome messege and ask the user to enter their pin number.
    cout<< "Welcome to the " << bankName <<"." <<endl;
    cout<< "Please enter you PIN: ";
        cin>> pinUser;


    if(pinUser != pinFile){ // log the number of attempts the user makes entering
        while(pinUser != pinFile){ //the pin number. If the pin number entered
                        //fails to matcht he pin number from the file, prompt
                        //the user to reenter it, and add 1 to the attempts counter.
            cout<< "Invalid PIN; please reenter your PIN: ";
                cin >> pinUser;
            attempts += 1;

            if(attempts==3){ // once the counter reaches three, lock the user
                            // out of the system, and set pinFile = pinUser to
                            // end the while loop.
                cout<< "You have been lockes out of the system, please reinsert "
                    << "your card."<<endl;
                pinFile = pinUser;
            }
        }
    }
    else{ //once the pin entered by the user matches the pin from the file, 
         // exeute the following code:

        // Display the transaction info; with the account number, the ATH
        // number, and the current date the transaction is performed.
        // Display the initial balance of the user. Display, formated a 
        // column for the transaction type, a column for the ammount of 
        // money manipulated, and a column for the current balance.
        writeTransInfo<< "Transaction info for account no." << accNo
                      << " On ATH no. " << athNo << " On " << currentTime
                      <<endl;
        writeTransInfo<< "Initial Balance: " << initBalance <<endl;
        writeTransInfo<< "TRANSACTION" <<setw(15)<< "AMMOUNT" <<setw(15)
                      << "BALANCE" <<setw(15)<< "DATE" <<endl;
        //Welcome the user, and and ask them what they would like to do.
        cout<< "Welcome " << firstName << " " << lastName << "!\n"
            << "What would you like to do? ";

        do{
            // Display the menu of choices the user has. The user can press 0
            // to exit the ATH, press 1 to make a deposit, press 2 to make a
            // withdrawal, and press 3 to check the balance.
            cout<< "Press 0 to exit." <<endl;
            cout<< "Press 1 to deposit money." <<endl;
            cout<< "Press 2 to withdraw money." <<endl;
            cout<< "Press 3 to check your balance." <<endl;
                cin>> choice; //prompt the user to enter their choice.

            if(choice == 1){ //If the user picks 1, ask them how much they 
                            // want to deposit.
                cout<< "How much would you like to deposit? " <<endl; 
                    cin>> deposit;

                while(deposit < 0){ //If the deposit is a negative number, 
                                    //Display an error messege, and prompt the
                                    //user to reeneter the deposit.
                    cout<< "Invalid ammount. Please reenter ammount to deposit."
                        <<endl;
                        cin>> deposit;
                }
              
                    currentBalance += deposit; //add the deposit to the current
                                               // balance of the user

                    // Show how much the user deposited and then ask them if
                    // they wish to continue.
                    cout<< "You have deposited $" << deposit << ".\n"
                        << "Do you wish to conitnue? Enter 1 for yes, enter "
                        << "2 for no."<<endl;
                        cin >> yesNo;
                        
                        //if the user does not enter 1 or 2, display an error
                        //messege, and tell them to enter 1 or 2.
                        while(yesNo != 1 && yesNo != 2){
                             cout<< "Please enter 1 for yes or 2 for no." <<endl;
                                cin>> yesNo;
                        }

                        if(yesNo == 1){ //if 1, set choice = -99. and take them
                            choice == -99; //back to the menu.
                        }
                        else if(yesNo == 2 ){ //If 2, set choice = 0, and exit
                            choice = 0; // the program.
                            cout<< "Exiting." <<endl; // display an exit messege.
                        }
                // Write and format the transaction info for the deposit into 
                // repciept.txt
                writeTransInfo<< "Deposit: "<< setw(15)<< deposit <<setw(15)
                              << currentBalance <<setw(30)<< currentTime <<endl;
            }
            else if(choice == 2){ // If the user picks 2, ask them how much they
                        // would like to withdraw, prompt them to enter multiples
                        // of $10
                cout<< "Enter how much money you would like to withdraw "
                    << "(enter in multples of $10)? " <<endl; 
                    cin>> withdrawal;

                while(withdrawal <0 || withdrawal%10 || currentBalance-withdrawal<0){ 
                    // if the withdraw ammount is less than 0, or not a multiple
                    // of 10, or, if the current balance becomes negatice, give 
                    // an error messege and prompt the user to enter the correct
                    // ammount.
                    if(currentBalance-withdrawal<0){
                        cout<< "You do not have available funds to withdraw this "
                            << "ammount." <<endl;
                            cin>> withdrawal;
                    }
                    else{
                        cout<< "Invalid ammount, please enter in multiples of $10."
                            <<endl;
                            cin>> withdrawal;
                    }
                }

                currentBalance -= withdrawal; // subtract the withdrawal from 
                        // the current balance.

                // tell the user how much they withdrew, and if they wish to
                // continue.
                cout<< "You have withdrawed $" << withdrawal << ".\n"
                    << "Do you wish to conitnue? Enter 1 for yes, enter "
                    << "2 for no."<<endl;
                    cin >> yesNo;

                    while(yesNo != 1 && yesNo != 2){
                        cout<< "Please enter 1 for yes or 2 for no." <<endl;
                        cin>> yesNo;
                    }

                    if(yesNo == 1){
                        choice == -99;
                    }
                    else if(yesNo == 2 ){
                        choice = 0;
                        cout<< "Exiting." <<endl;
                    }

                // write and format the the transaction info of the withdrawal
                // to reciept.txt
                writeTransInfo<< "Withdrawal: "<< setw(12)<< withdrawal 
                    <<setw(15) << currentBalance <<setw(30)<< currentTime <<endl;
            }
            
            else if(choice == 3){ //if the user enters 3, display their current
                        //balance and ask if they would like to continue.
                cout<< "Your current balance is: " << currentBalance <<endl; 
                cout<< "Do you wish to conitnue? Enter 1 for yes, enter "
                    << "2 for no."<<endl;
                    cin >> yesNo;

                    while(yesNo != 1 && yesNo != 2){
                        cout<< "Please enter 1 for yes or 2 for no." <<endl;
                        cin>> yesNo;
                    }


                    if(yesNo == 1){
                        choice == -99;
                    }
                    else if(yesNo == 2 ){
                        choice = 0;
                        cout<< "Exiting." <<endl;
                    }

                 // write  and format the transaction for the balance check to
                 // reciept.txt
                 writeTransInfo<< "Balance Check: "<< setw(9)<< currentBalance 
                    <<setw(15) << currentBalance <<setw(30)<< currentTime <<endl;

            }
            else{ // if the user enters any other digit, execute the following.
                if(choice != 0){ //if the user does't enter 0, display an error
                    //messege and prompt them to reneter their choice.
                    cout<< "Please enter a valid menu option." <<endl;
                }
                else{ //if the user enters 0, exit the program.
                    cout<< "Exiting." <<endl; // display an exit messege.
                }
            }
        }while(choice != 0);

        writeTransInfo<<endl; // creates a new line to be able to seperate 
                    // better different transaction instances.
        writeTransInfo.close(); //close userInfo.txt from writing.
    }
//----------------------------------------------------------------------------
    return 0;
}
