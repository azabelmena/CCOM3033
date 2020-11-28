/*
ccomFiles.cpp

An example on how to use files in C++.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<string>
#include<fstream> //includes the fstream header file that allows one to manipulate 
using namespace std; // files.

int main(){

    //File objects
    
    ifstream readFile, exists; // creates the ifstream object to read from files.
    ofstream writeFile; // creates the ofstream object to write to files.

    // Variables

    bool openFailed;
    string fileName, fileName2; //stores the files (with file path).
    string dummy; 
    char overwrite = 'y';

    do{ // create a control sequence that allows the user to renter a the file 
        // they wish to open; considering the file they typed in does't exist, 
        // or that their file path was incorrect.

        openFailed = false; //our bool which will let us know whether the file 
                            // was successfully read. false indicates the file 
                            // was read, true indicates the file was not read.

        cout<< "Enter the file (with absolute path) you want to read from: ";
            cin>> fileName; //prompt the user to enter the file they wish to read
                            //from.

        readFile.open(fileName); //opens the file that is to be read.
        
        if(readFile.fail()){ // If the file was not read, executes the error messege.
            cout<< "Failed to read file. Please make sure the file exists and "
                <<"that your file path is correct.\n" <<endl;
            openFailed = true; //sets true to allow the control sequence to loop 
                              // and allow the user to try again.
                              
            readFile.clear(); //clears the file buffer.
        }
    }while(openFailed); 


    do{
        cout<< "Enter the name (with file path) of the file you "
            << "want to write to: "; //prompt the user to enter the file they 
                                    // wish to write to (with the file path).
            cin>>fileName2;

            exists.open(fileName2); // checks to see if the file entered exists
                                    // by trying to read it. 
        
            if(exists){ // if the file already exists, ask the user if they wish
                        // to overwrite it.
                cout<< "That file exists, do you wish to overwrite it? (y/n): ";
                    cin>> overwrite;
            }
        exists.close(); //closes the file.
      }while(overwrite == 'n' || overwrite == 'N');

    writeFile.open(fileName2); //opens the file for reading.

    while(!readFile.eof()){ // Reads the file until it finds the end of the file.
        getline(readFile, dummy); //reads the contents of the file into dummy.
    
        writeFile<< dummy <<endl; //Writes the contents of the file into 
                                  // another file.
    }

    writeFile.close(); //closes the file after the program is done executing.
    readFile.close(); //closes the file after the program is done executing.

    return 0;
}
