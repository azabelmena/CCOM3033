#include<iostream> // include the appropriate header files.
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include"ath.h"
using namespace std;

// Read::open takes the ifstream object as reference, as well as the file path as arguments.
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

// Read::close must takes the ifstream object as an argument.
void Read::close(ifstream& readFile){
    readFile.clear(); // clear the read buffer.
    readFile.close(); // close the file from readUserInfo.
}

// read takes the ifstream argument and an Account argument so that it 
// can read the appropriate information from the file into an Account struct.
void Read::read(ifstream& read, Account& account){
   string accountNo, userName, first, last, socialSec, pinNum, userBalance; // these are 
                // place holder variables.

   getline(read, account.bankName, '\n'); // get the bank's name.

   read>> accountNo >> account.accNo; // read the account number
   read>> userName >> first >> last; // read the first and the last name
        account.name = first+" "+last; // concatenate the first and last name.
   read>> socialSec >> account.socSec; // read the social security number.
   read>> pinNum >> account.userPin; // read the pin number (used for validation).
   read>> userBalance >> account.currentBalance; // read the user's balance.
}

// Takes the ifstream object, as a well as a TransactionInfo struct, and a vector of
// TransactionInfos, so that (if present), it reads the transaction info from the file into a struct 
// which it then pushe back into the vector.
vector<TransactionInfo> Read::read(ifstream& readFile,TransactionInfo transactionInfo, vector<TransactionInfo> transactions){ 
    unsigned atm; //declare an atm variable.
    string trans, fecha; // declare transaction and date variables.
    double ammt, bal; // declare ammount and balance variables.

    string empty, header; // variables to store the empty line and the header.

    getline(readFile, empty, '\n'); // get the empty line.
    getline(readFile, header, '\n'); // get the header.

    // while the readFile is not at the end of the file:
   do{
       readFile>> atm >> trans >> ammt >> bal; // read into the variables
       getline(readFile, fecha, '\n'); // get the date.

       transactionInfo = {atm, trans, ammt, bal, fecha}; // initialize the 
                                // struct transaction to store these variables.

       transactions.push_back(transactionInfo); // push transactionInfo into transactions.

   }while(readFile); // while the ifstream has not reached the end of the filel.

   return transactions; // return the vector of transactions.
}

// does the exact same as Read::open, except with an ofstream object.
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

// same as Read::close, but witht he ofstream object.
void Write::close(ofstream& writeFile){
    writeFile.clear(); //clear the write buffer.
    writeFile.close(); // close the file from writeUserInfo.
}

// Takes the ofstream object as an argument and writes the 
// transaction info header to the file.
void Write::setHeader(ofstream& write){
    write<<"\nATH" << setw(15) << "TRANSACTION" <<setw(15)<< "AMMOUNT" <<setw(15)<< "BALANCE" <<setw(15)
         << "DATE" <<endl;
}

// does the same as the previous, except instead of writing 
// to the file, it prints the header onto the screen, hence it takes no args.
void Write::setHeader(){
    cout<<"\nATH" << setw(15) << "TRANSACTION" <<setw(15)<< "AMMOUNT" <<setw(15)<< "BALANCE" <<setw(15)
         << "DATE" <<endl;
}


// writes the user's account information into the file, hence which is why 
// it takes an Account struct as an argument. We do this because we are essentially 
// overwriting the entire file, so we have to call the user's information 
// stored into the Account struct to rewrite the user's info back into the file.
void Write::write(ofstream& write, Account& account){
    write<< account.bankName <<endl; // write the bank name.
    write<< "account_No:" << setw(15) << account.accNo <<endl; // write the account number.
    write<< "Name:" << setw(27) << account.name <<endl; // write the user's name.
    write<< "Soc_Security:" << setw(15)<< account.socSec <<endl; // write the social security.
    write<< "PIN:" << setw(17) << account.userPin <<endl; // write the user's pin number.
    write<< "Balance: "<< setw(12) << account.currentBalance <<endl; // write the current balance of the user.
}

// This is the overloaded write function which takes the vector of transaction infos 
// as an additional argument instead of the Account struct, this write function writes the account 
// info into the file appending it (depsite that we are overwritting the entire file) to the user's
// information.
void Write::write(ofstream& write, vector<TransactionInfo> transaction){
    // for i <= transaction.size, write the ith member of the transaction info into the file, where 
    // the members are in the set {athNo, transaction, ammount, balance, date}.
    for(int i = 0; i < transaction.size() ; i++){
        write<< transaction[i].athNo << setw(15) << transaction[i].transaction << setw(15) 
            << transaction[i].ammount << setw(15) << transaction[i].balance << setw(30) << transaction[i].date<<endl;
    }
}


// This is the depositCash function
double Transaction::depositCash(){
    double deposit;

    // ask the user how much they would like to deposit.
    cout<< "How much would you like to deposit?" <<endl;
        cin>> deposit;

    // if the deposit isn't whole dollar ammounts, reprompt the user.
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

    return deposit; // return the deposited ammount.
}

// This is the depositCheck function. It does the same thing as 
// the deposit cash function, with the added caveat that it restricts the user to 
// an upperbound of $5000.00
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

// This is the withdraw function. bal is taken as an 
// argument, because we will check this against the ammount the user 
// enters to see if they end up going overbudget.
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

    return withdrawal; // return the ammount withdrawn.
}

// This is the check balance function, and all it does is 
// displays the user's current balance, hence why it bal as 
// an argument.
void Transaction::checkBal(double& bal){
    cout<< "Your current balance is: " << bal << "." <<endl;
}

// This is the lookFor function. The user enters, as a string 
// the transaction they woulf like to search for (limited to deposit, withdrawal, 
// and balance_check), and returns the string entered. This string will be used as the 
// search term in the following function.
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

// This is the search fucntion, which takes as arguments, the search term entered by the user, a
// vector of transaction infos, and a vector of ints. The ints will be used to store the index of
// the elements of the TransactionInfo vector.
void Search::search(string searchTerm, vector<TransactionInfo> transactionInfo, vector<int> index){
    int first = 0, last = transactionInfo.size()-1; // set the first and last indices.

    while(first <= last){ // while first <= last,
        if(searchTerm == transactionInfo[first].transaction){ //if the user input matches the 
            index.push_back(first); //vector element at index first, push first into the
        }                           // index vector.

        first++; // increment first.
    }

    // print the transactions that were found.
    for(int i = 0; i < index.size(); i++){
        cout<< transactionInfo[index[i]].athNo << setw(15) << transactionInfo[index[i]].transaction << setw(15)
            << transactionInfo[index[i]].ammount << setw(15) << transactionInfo[index[i]].balance << setw(30)
            << transactionInfo[index[i]].date <<endl;
    }
}
