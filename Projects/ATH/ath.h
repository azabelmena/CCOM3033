#ifndef ATH_H
#define ATH_H

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
        void read(std::ifstream&,std::string&, std::string&, std::string&, std::string&, std::string&, double&);
};

class Write{
    public:
        bool open(std::ofstream&, std::string);
        void close(std::ofstream&);
        void setHeader(std::ofstream&);
        void write(std::ofstream&, std::string, std::string&, double&, double&, unsigned&);
};

class Menu{ //done
    public:
        Menu(){
            std::cout<< "Press 0 to exit." <<std::endl;
            std::cout<< "Press 1 for deposits." <<std::endl;
            std::cout<< "Press 2 for withdrwawals." <<std::endl;
            std::cout<< "Press 3 for an audit." <<std::endl;
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

//class Search{
    //public:
        //std::string lookFor();
        //void search(std::string, std::vector<std::string>&, std::vector<int>&);
        //void printFound(std::vector<int>&, std::vector<int>&, std::vector<std::string>&, std::vector<double>&, std::vector<double>&, std::vector<std::string>&);
//};

struct Account{
    std::string bankName;
    std::string accNo;
    std::string name;
    std::string socSec;
    std::string userPin;
    double initBalance;
    double currentBalance;
};

struct TRANSACTION{
    int athNo;
    std::string transaction;
    double ammount;
    double balance;
    std::string date;
};

 
#endif
