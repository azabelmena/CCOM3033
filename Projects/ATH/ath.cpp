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

void Read::read(ifstream& read, Account& account){
   string accountNo, userName, first, last, socialSec, pinNum, userBalance, empty; // these are 
                // place holder variables.

   getline(read, account.bankName, '\n'); // get the bank's name.

   read>> accountNo >> account.accNo; // read the account number
   read>> userName >> first >> last; // read the first and the last name
        account.name = first+" "+last; // concatenate the first and last name.
   read>> socialSec >> account.socSec; // read the social security number.
   read>> pinNum >> account.userPin; // read the pin number (used for validation).
   read>> userBalance >> account.currentBalance;

   read>>empty;
}

vector<TransactionInfo> Read::read(ifstream& readFile,TransactionInfo transactionInfo, vector<TransactionInfo> transactions){ 
    unsigned atm; //declare an atm variable.
    string trans, fecha; // declare transaction and date variables.
    double ammt, bal; // declare ammount and balance variables.

    string empty, header; // variables to store the empty line and the header.

    getline(readFile, empty, '\n');
    getline(readFile, header, '\n');

    // while the readFile is not at the end of the file:
   do{
       readFile>> atm >> trans >> ammt >> bal; // read into the variables
       getline(readFile, fecha, '\n'); // getline the date.

       transactionInfo = {atm, trans, ammt, bal, fecha};

       transactions.push_back(transactionInfo);

   }while(readFile); 

   return transactions;
}


bool Write::open(ofstream& writeFile, string filename){
    writeFile.open(filename); // open the same file.

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

void Write::setHeader(){
    cout<<"\nATH" << setw(15) << "TRANSACTION" <<setw(15)<< "AMMOUNT" <<setw(15)<< "BALANCE" <<setw(15)
         << "DATE" <<endl;
}


void Write::write(ofstream& write, Account& account){
    write<< account.bankName <<endl<<endl;
    write<< "account_No:" << setw(15) << account.accNo <<endl;
    write<< "Name:" << setw(27) << account.name <<endl;
    write<< "Soc_Security:" << setw(15)<< account.socSec <<endl;
    write<< "PIN:" << setw(17) << account.userPin <<endl;
    write<< "Balance: "<< setw(12) << account.currentBalance <<endl;
}

void Write::write(ofstream& write, vector<TransactionInfo> transaction){
       for(int i = 0; i < transaction.size() ; i++){
           write<< transaction[i].athNo << setw(15) << transaction[i].transaction << setw(15) 
               << transaction[i].ammount << setw(15) << transaction[i].balance << setw(30) << transaction[i].date<<endl;
       }
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



string Search::lookFor(){
    string transactionName; // store the user's input.

    // ask the user which transaction they would like to look for.
    cout<< "What transaction would you like to look for?\n"
        << "Deposit\n" << "Withdrawal\n" << "Balance_Check\n";
        cin>> transactionName;


    // the following case handelling for the user input.
    if(transactionName == "deposit" || transactionName == "DEPOSIT"){
            transactionName = "Deposit";
    }

    if(transactionName == "withdrawal" || transactionName == "WITHDRAWAL"){
            transactionName = "Withdrawal";
    }

    if(transactionName == "balance_check" || transactionName == "BALANCE_CHECK"){
            transactionName = "Balance_Check";
    }

    // while the user enters anything other than the appropriate options, reprompt
    // the user.
    while(transactionName != "Deposit" && transactionName != "Withdrawal" && transactionName != "Balance_Check"){
        cout<< "Please enter one of the following transactions \n" 
            << "Deposit \n" << "Withdrawal\n" << "Balance_Check\n";
            cin >>transactionName;
    }

    return transactionName; // return the user input.
}
void Search::search(string searchTerm, vector<TransactionInfo> transactionInfo, vector<int> index){
    int first = 0, last = transactionInfo.size()-1; // set the first and last indices.

    while(first <= last){ // while first <= last,
        if(searchTerm == transactionInfo[first].transaction){ //if the user input matches the 
            index.push_back(first); //vector element at index first, push first into the
        }                           // index vector.

        first++; // increment first.
    }

    for(int i = 0; i < index.size(); i++){
        cout<< transactionInfo[index[i]].athNo << setw(15) << transactionInfo[index[i]].transaction << setw(15)
            << transactionInfo[index[i]].ammount << setw(15) << transactionInfo[index[i]].balance << setw(30)
            << transactionInfo[index[i]].date <<endl;
    }
}
