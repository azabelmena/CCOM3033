#ifndef ATH_H
#define ATH_H

struct Account{
    std::string bankName;
    std::string accNo;
    std::string name;
    std::string socSec;
    std::string userPin;
    double currentBalance;
};

struct TransactionInfo{
    unsigned athNo;
    std::string transaction;
    double ammount;
    double balance;
    std::string date;
};


class Validation{ //done
    public:
        Validation(std::string& pinNum){
            int attempts = 1;
            bool validated = false;
            std::string pin;

            std::cout<< "Please enter your PIN: ";
                std::cin>> pin;

            if(pin == pinNum){
                validated = true;
            }

            while(!validated && attempts<3){
                attempts += 1;

                std::cout<< "Invalid PIN. Please reenter your PIN "
                    << "(You have " << 3-attempts << " attempts left):";
                    std::cin>> pin;

                if(pin == pinNum){
                    validated = true;
                }
            }
            if(!validated){
                std::cout<< "You have been locked out... We are calling the cops!" <<std::endl;

                exit(EXIT_FAILURE);
            }
        }
};

class Read{
    public:
        bool open(std::ifstream&, std::string);
        void close(std::ifstream&);
        void read(std::ifstream&, Account&);
        std::vector<TransactionInfo> read(std::ifstream& readFile,TransactionInfo, std::vector<TransactionInfo>);
};

class Write{
    public:
        bool open(std::ofstream&, std::string);
        void close(std::ofstream&);
        void setHeader(std::ofstream&);
        void setHeader();
        void write(std::ofstream&, Account&);
        void write(std::ofstream&, std::vector<TransactionInfo>);
        

};

class Menu{ //done
    public:
        Menu(){
            std::cout<< "Press 0 to exit." <<std::endl;
            std::cout<< "Press 1 for deposits." <<std::endl;
            std::cout<< "Press 2 for withdrwawals." <<std::endl;
            std::cout<< "Press 3 for a Balance Check." <<std::endl;
            std::cout<< "Press 4 to search for a transaction." <<std::endl;

        }
};

class Transaction{
    public:
        double depositCash();
        double depositCheck();
        double withdraw(double&);
        void checkBal(double&);
};


class Search{
    public:
        std::string lookFor();
        void search(std::string&, std::vector<TransactionInfo>&, std::vector<int>);
};
 
#endif
