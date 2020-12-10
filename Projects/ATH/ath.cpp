#include<iostream> // include the relevant header files.
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include"ath.h"
using namespace std;

bool Read::open(ifstream& readFile, string filename){ //open the file for reading.
    readFile.open(filename); // open the file name

    if(readFile.fail()){ // if the file fails to open, set openRead to false.
        cout<< "Could not open file." <<endl;

        return false;
    }
    else{ // set it true once the file is opened.
        return true;
    }
}

void Read::close(ifstream& readFile){ // close the file from reading.
    readFile.clear(); // clear the read buffer.
    readFile.close(); // close the file from readUserInfo.
}

// Read the user's account info from the file into the members of the Account struct account.
void Read::read(ifstream& read, Account& account){
   string accountNo, userName, first, last, socialSec, pinNum, userBalance, empty; // these are 
                // place holder variables.

   getline(read, account.bankName, '\n'); // get the bank's name.

   read>> accountNo >> account.accNo; // read the account number
   read>> userName >> first >> last; // read the first and the last name
        account.name = first+" "+last; // concatenate the first and last name.
   read>> socialSec >> account.socSec; // read the social security number.
   read>> pinNum >> account.userPin; // read the pin number (used for validation) 
   read>> userBalance >> account.initBalance;
   read>> userBalance >> account.currentBalance;

   read>>empty;
}

// Reads the transaction info into a vector of TransactionInfo structs.
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

       transactionInfo = {atm, trans, ammt, bal, fecha}; // store the values into the struct.

       transactions.push_back(transactionInfo); // push back into the vector.

   }while(readFile); // While the end of the file has not been reached. 

   return transactions; // return the vector of TransactionInfo structs.
}


// Opens the file for writing (note this overwrites the entire file).
bool Write::open(ofstream& writeFile, string filename){
    writeFile.open(filename, ios::app); // open the same file.

    if(writeFile.fail()){
        cout<< "Could not open file." <<endl;

        return false;
    }
    else{
        return true;
    }
}

void Write::close(ofstream& writeFile){ // closes the file from writing.
    writeFile.clear(); //clear the write buffer.
    writeFile.close(); // close the file from writeUserInfo.
}

// Sets the transaction header to be written in the file.
void Write::setHeader(ofstream& write){
    write<<"\nATH" << setw(15) << "TRANSACTION" <<setw(15)<< "AMMOUNT" <<setw(15)<< "BALANCE" <<setw(15)
         << "DATE" <<endl;
}

void Write::setHeader(){ //prints the transaction header on the screen.
    cout<<"\nATH" << setw(15) << "TRANSACTION" <<setw(15)<< "AMMOUNT" <<setw(15)<< "BALANCE" <<setw(15)
         << "DATE" <<endl;
}


// Writes the contents of the vector of TransactionInfo structs, transaction into the file, used to 
// recover data that has been overwritten.
void Write::write(ofstream& write, vector<TransactionInfo> transaction){
       for(int i = 0; i < transaction.size() ; i++){
           write<< transaction[i].athNo << setw(15) << transaction[i].transaction << setw(15) 
               << transaction[i].ammount << setw(15) << transaction[i].balance << setw(30) << transaction[i].date<<endl;
       }
}

//  the depositCash function.
double Transaction::depositCash(){
    double deposit;

    // ask the user how much they would like to deposit.
    cout<< "How much would you like to deposit?" <<endl;
        cin>> deposit;

    while(deposit-static_cast<int>(deposit)){ // Assure the user can only enter whole dollar ammounts.
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

    return deposit; // return the ammount deposited.
}

// The depositCheck function, the only difference is that this gives the 
// user an upperbound of $5000 of how much they can deposit.
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

// The withdraw function. Takes the user's balance as an argument, and 
// stops the user from withdrawing anything higher than their current balance. Other than 
// that, it withdraws dollar ammounts that are multiples of 10.
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

    return withdrawal; //returns the amount withdrawn.
}

// The checkBal function, takes the user's current balance and prints it on 
// the screen.
void Transaction::checkBal(double& bal){
    cout<< "Your current balance is: " << bal << "." <<endl;
}

// The lookFor function, prompts the user to enter either:
// "Depsoit", "Withdrawals", or "Balance_Check", and reprompts them if 
// they enter anything else (with some exceptions).
string Search::lookFor(){
    string transactionName; // store the Chosen string.
    int choice;

    // ask the user which transaction they would like to look for.
    cout<< "What transaction would you like to look for?\n"
        << "Press 1 for deposit\n" << "Press 2 for withdrawal\n" << "Press 3 for balance_Check\n";
        cin>> choice;

    // reprompt the user if they enter an invalid input.
    while(choice != 1 && choice != 2 && choice !=3){
        cout<< "Press 1 for Deposit\n" << "Press 2 for Withdrawal\n" << "Press 3 for Balance_Check\n";
        cin>> choice;
    }

    if(choice == 1){
        transactionName = "Deposit";
    }
    else if(choice == 2){
        transactionName = "Withdrawal";
    }
    else{
        transactionName = "Balance_Check";
    }

    return transactionName; // return the user input.
}

// The searchFunction, takes as arguments the string returned by lookFor, a vector of
// TransactionInfo structs, and an index vector. This program searches for the transaction that
// matches the searchTerm string, and prints them (if any) on the screen. If none are found, it
// simply says "no transactions found."
void Search::search(string& searchTerm, vector<TransactionInfo>& transactionInfo, vector<int> index){
    Write writeHeader; // declare writeHeader to write the header.
    int first = 0, last = transactionInfo.size()-1; // set the first and last indices.
    bool found = false;

    while(first <= last){ // while first <= last,
        if(searchTerm == transactionInfo[first].transaction){ //if the user input matches the 
            index.push_back(first); //vector element at index first, push first into the index
            
            found = true; // set found true.
        }

        first++; // increment first.
    }
    
    if(found){ // if found is true:
        writeHeader.setHeader(); // print the header on the screen.
        for(int i = 0; i < index.size(); i++){ // print the matching transactions.
            cout<< transactionInfo[index[i]].athNo << setw(15) << transactionInfo[index[i]].transaction << setw(15)
                << transactionInfo[index[i]].ammount << setw(15) << transactionInfo[index[i]].balance << setw(30)
                << transactionInfo[index[i]].date <<endl;
        }

    }
    else{
        cout<< "Transactions not found." <<endl;
    }
}
