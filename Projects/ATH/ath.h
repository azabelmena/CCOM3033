/*
ath.h

Here is where we define the structs and classes necessary for the program to fucntion. 
There are two structs, which are used for storing data, and the classes consist solely of public member
functions, some of which are constructors. 
*/
#ifndef ATH_H
#define ATH_H

// This is the account struct, which is meant to store the user's 
// account data from the file.
struct Account{
    std::string bankName; // store the bank's name.
    std::string accNo; // store the user's account number.
    std::string name; // store the user's name.
    std::string socSec; // store the social security.
    std::string userPin; // store the PIN (used for accessing the atm).
    double initBalance; // stores the user's initial balance.
    double currentBalance; // store the current balance (upon first execution, this is the initBalnace,
                        // on all other subseequent excutions, it is the current balance).
};

// We define a transactionInfo to be a transaction of the form:
// ATH      TRANSACTION     AMMOUNT     BALANCE     DATE
// Where ATH is a randomly generated atm machine number between 1 and 500, TRANSACTION is the 
// name of the transaction realized, AMMOUNT is the ammount of the transaction, BALANCE is the
// user's current balance after the transaction (in the case of balance checks, both AMMOUNT and ,
// AMMOUNT is the ammount of the transaction, BALANCE is the user's current balance after the
// transaction (in the case of balance checks, both AMMOUNT and BALANCE are the user's current
// balance), and DATE is just the date of the transaction.
struct TransactionInfo{
    unsigned athNo; // store the atm number.
    std::string transaction; // store the transaction name.
    double ammount; // store the transaction ammount.
    double balance; // store the balance after the transaction.
    std::string date; //store the date.
};

// The validation class is used to validate the pin of the user, and consists
// only of the Validation constructor. THe constructor takes as an argument, as a string,
// the PIN from the user's file and that string is then comapred to a pin entered in the prompt. If they
// match, the program continues executing, if they don't we call the cops and exit the program.
class Validation{
    public:
        Validation(std::string& pinNum){
            int attempts = 1; // Initialize attempts to 1.
            bool validated = false; // initialize validated to false.
            std::string pin;

            //prompt the user to enter the pin.
            std::cout<< "Please enter your PIN: ";
                std::cin>> pin;

            // if the pin is correct,
            if(pin == pinNum){
                validated = true;
            }

            // while the pin is not validated, and the attempts are less than 3
            while(!validated && attempts<3){
                attempts += 1; // increment attempts by 1

                // reprompt the user.
                std::cout<< "Invalid PIN. Please reenter your PIN "
                    << "(You have " << 3-attempts << " attempts left):";
                    std::cin>> pin;

                if(pin == pinNum){ // if the pins match, set validated true
                    validated = true;
                }
            }
            if(!validated){ //else, call the cops and exit the program.
                std::cout<< "You have been locked out... We are calling the cops!" <<std::endl;

                exit(EXIT_FAILURE);
            }
        }
};

// The read class defines a set of public member functions that are in charge of 
// reading from the file. Two of these are constructors, and takes as additional 
// arguments, an Account struct, and a vector of TransactionInfo structs, respectively, 
// this is so that the user's information and the transaction info can be read into the appropriate
// variables.
class Read{
    public:
        bool open(std::ifstream&, std::string); // opens the file.
        void close(std::ifstream&); // closes the file.
        void read(std::ifstream&, Account&); // reads the user's information from the file.

        // reads the transaction information from the file.
        std::vector<TransactionInfo> read(std::ifstream& readFile,TransactionInfo, std::vector<TransactionInfo>);
};

// THe write class is similar to the read class, but for writing instead of reading. What the 
// essential functions of the class do is overwrite the contents of the file, this is why we 
// read the user's information and the transaction info into structs, so that we can rewrite them
// into the file once the program is done.
class Write{
    public:
        bool open(std::ofstream&, std::string); // opens the file.
        void close(std::ofstream&); // closes the file.
        void setHeader(std::ofstream&); // writes the transaction header into the file
        void setHeader(); // prints the transaction header in the command line.
        void write(std::ofstream&, Account&); // writes the user's information into the file.
        void write(std::ofstream&, std::vector<TransactionInfo>); // writes the transaction info into the file.
};

// Like the validation class, the menu class consists just of the constructor Menu, which 
// prints the menu of options onto the screen.
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

// The transaction class consists of a set of public member functions that 
// are used for the purposes of the transaction. They manipulate the user's balance, and 
// in accordance to the transaction, stores the new balance into the currentBalance variable. 
// THe transactions are deposit (cash or check), which take no args, withdraw, which takes as an 
// argument the user's current balance, so that it can check against what the user enters and
// make sure we are not withdrawing an illegal ammount, the last is the checkBal which takes the
// current balance of the user, however, it just prints the current balance on the screen.
class Transaction{
    public:
        double depositCash(); // make a cash deposit.
        double depositCheck(); // makes a check deposit, with $5000 as an upperbound for how much can be deposited.
        double withdraw(double&); // withdraws maoney within the alotted ammount.
        void checkBal(double&); // prints the user's balance on the screen.
};

// The search class consists of two public member functions that are used for 
// searching through transactions. The function look for takes no arguments, andd returns a string, 
// and search takes as args what look for returns, a vector of TransactionInfo structs, and a vector 
// of ints that will serve as indexes for transaction names that match the lookFor string.
class Search{
    public:
        std::string lookFor(); // looksfor the strings "Depsoit", "Withdrawal", and "Balance_Check".
        void search(std::string&, std::vector<TransactionInfo>&, std::vector<int>); // searches
                // through the vector of structs, and prints any found members onto the screen.
};
 
#endif
