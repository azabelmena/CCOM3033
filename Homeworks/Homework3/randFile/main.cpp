#include <iostream>
#include<cstdlib> // imnport the random number generator
#include<ctime> // import the time
#include<iomanip> // for formatting the file
#include<fstream> // for writing to and reading from the file

using namespace std;

int main(){

    // we create our file manipulaltion objects.
    ofstream writeFile; // writes to the file.
    ifstream readFile; //reads from the file.

    clock_t clicks;
    clicks = clock();

    unsigned seed = time(0); // our seed for the random numbers
    srand(seed); //we seed our random numbers

    // randomNumbers is the file we will be writing and reading
    writeFile.open("../randomNumbers.txt");
    readFile.open("../randomNumbers.txt");

    int largest = 0; // create an integer that stores the largest number.

    for(int j = 0; j < 5; j++){ //this for loop creates the 10x5 matrix
        for(int i = 0; i < 10; i++){ // we will be storing our numbers in.

            int sequence = rand();

            if(largest < sequence){ // we compare our random number with
                largest = sequence; // the largest number. If the random
                        // number is bigger, we make it the largest number.
            }

            writeFile<<setw(12)<<sequence; // display the rows

            clicks += 1;
        }
        writeFile<<setw(12)<<clicks<<setw(12)<<largest<<endl; // display the largest number
                // and then display the next column.
        largest = 0;
    }

    clicks -= clock();

    writeFile.close(); // we close the file off to writing.
    readFile.close(); // we close the file off to reading.

    return 0;

}
