#ifndef ATH_H
#define ATH_H

class Ath{
    private:

    public:
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
};

#endif
