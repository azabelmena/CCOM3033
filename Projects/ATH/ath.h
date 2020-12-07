/*
ath.h

This is the header file for the program, and contains all the code necessary for it to function.
We use two structs to store information, and we use classes to manipulate the data within those structs.
All classes here consist of just public member functions.
*/
#ifndef ATH_H
#define ATH_H

// This is the struct used to store the user's account information. We store the bank's namme,
// the user's account number, their name, their social security, their PIN (used for accessing the
// atm), and their  current balance.
// (note, the instructions asked for the initial AND the current balance, however, since the initial
// balance is only ever used once, and the current balanced is used for all subsequent executions of
// the program, we have decided to use one variable to store the balance).
struct Account{
    std::string bankName; // store the bank name.
    std::string accNo; // store the user's account number.
    std::string name; // store the user''s name.
    std::string socSec; // store the social security.
    std::string userPin; // store the user's PIN.
    double currentBalance; // store the user's (current) balance.
};

// transactions have the following format:
// ATH      TRANSACTION     AMMOUNT     BALANCE     DATE
// Where ATH is a randomly generated integer number, transaction is the transaction's name (i.e
// deposit, withdrwawal, or balance check), the ammount referes to the ammount of money transacted 
// (in the case of the balance check this is just the user's current balance), the balance is the
// current balance of the user (after the transaction), and the date is the date the transaction was
// realized.
struct TransactionInfo{
    unsigned athNo; // store the randomly generated atm number.
    std::string transaction; // store the transaction name.
    double ammount; // store the ammount transacted.
    double balance; // store the current  balance.
    std::string date; // store the date of the transaction.
};

// This is the validation class, who's purpose is simply to validate the pin number 
// of the user, and consists just of the constructor Validation. The only argument it 
// takes is a string storing the pin number, which is what we validate against.
class Validation{
    public:
        Validation(std::string& pinNum){
            int attempts = 1; // set attempts = 1
            bool validated = false; // set validated false
            std::string pin; // delcare the pin number to be entered by the user.

            std::cout<< "Please enter your PIN: "; // prompt the user to enter their pin.
                std::cin>> pin;

            if(pin == pinNum){ // if the validation succeeds, set validated to true.
                validated = true;
            }

            // while the pin isn't validated, and the user has less than three attempts, execute 
            // the following:
            while(!validated && attempts<3){
                attempts += 1; // increment attempts by 1.

                // reprompt the user to enter their pin.
                std::cout<< "Invalid PIN. Please reenter your PIN "
                    << "(You have " << 3-attempts << " attempts left):";
                    std::cin>> pin;

                if(pin == pinNum){ // if the validation succeeds, set validated to true and 
                    validated = true; // exit the while.
                }
            }
            if(!validated){ // now if the user reaches 3 attempts, and the pins till isn't validated:
                // call the cops on them.
                std::cout<< "You have been locked out... We are calling the cops!" <<std::endl;

                exit(EXIT_FAILURE); // exit the program.
            }
        }
};

// this class is created for the sole purpose of reading from the file. Its functions are:
// open, close, and read (which is an overloaded constructor). Their descriptions are found below.
class Read{
    public:
        bool open(std::ifstream&, std::string); // opens the file for reading.
        void close(std::ifstream&); // closes the file from reading.
        void read(std::ifstream&, Account&); // reads the user's account info.
        
        //reads the transaction info from the file (if present).
        std::vector<TransactionInfo> read(std::ifstream& readFile,TransactionInfo, std::vector<TransactionInfo>);
};

// this class is created for the sole purpose of writing to the file. Its functions are:
// open, close, setHeader (which is overloaded) and write (which is an overloaded constructor). 
// Their descriptions are found below.
class Write{
    public:
        bool open(std::ofstream&, std::string); // opens the file to writing.
        void close(std::ofstream&); // closes the file from writing.
        void setHeader(std::ofstream&); // sets the header for the transaction info in the file.
        void setHeader(); // set the header for the transaction info on the command line (used for the search).
        void write(std::ofstream&, Account&); // write the user's account info to the file.
        void write(std::ofstream&, std::vector<TransactionInfo>); // write the transaction info to the file.
};

// This class just displays the menu.
class Menu{
    public:
        Menu(){
            std::cout<< "Press 0 to exit." <<std::endl;
            std::cout<< "Press 1 for deposits." <<std::endl;
            std::cout<< "Press 2 for withdrwawals." <<std::endl;
            std::cout<< "Press 3 for a Balance Check." <<std::endl;
            std::cout<< "Press 4 to search for a transaction." <<std::endl;

        }
};

// This is the class conssisting of all public member functions that will be used 
// to realize the desired transactions of the user. The following are:
// depositCheck, depositCash, withdraw, and checkBal, each of which is described below.
class Transaction{
    public:
        double depositCash(); // deposit a cash ammount to the user's balance.
        double depositCheck(); // deposit a check ammount to the user's balance.
        double withdraw(double&); // withdraw from the user's balance (takes the current balance as an argument).
        void checkBal(double&); // audit the user's current balance (takes the current balance as an argument).
};

// This is the class that consists of the member functions that will be used for searching the
// transactions. It consists of a function that looks for the transaction, and another that displays 
// the transations that match the search term on the screen (it does not write to the file).
class Search{
    public:
        std::string lookFor(); // returns the search term of the desired transaction.
        // prints all the transactions that match the search term. It takes as argument a vector of
        // the transaction info, because all it will print the transaction info to the screen.
        void search(std::string, std::vector<TransactionInfo>, std::vector<int>);
};
 
#endif
