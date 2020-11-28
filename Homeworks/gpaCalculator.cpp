/*gpaCalculator.cpp
 
This is a program that calculates the semester gpa of the user.

Created by: Alec Zabel-Mena.

*/
#include<iostream>
using namespace std;

int main(){
    int a, b, c, d ,f, sum; // declare integer variables to be used. each variable corresponds to a grade, for example
                            // a corresponds to the grade A. The one exception to this is the variable sum, which will
                            // be used in calculating the gpa

    double weight, gpa; // declares double variables to be used; one will be used to calculate the weighted sum of the
                        // grades, the other stores the gpa.

    // The following lines of code just ask the user how much of each grade they got in the semester.. The user is then
    // prompted to enter the number of the corresponding grade they recieved; for example:

    cout<< "How many A's did you get this semester? "; // Asks the user how many A's they recieved.

        cin>> a; // The user is then prompted to enter the number of A's they recieved.

    cout<< "How many B's did you get this semester? ";
        cin>> b;

    cout<< "How many C's did you get this semester? ";
        cin>> c;
        
    cout<< "How many D's did you get this semester? ";
        cin>> d;
        
    cout<< "How many F's did you get this semester? ";
        cin>> f;
    cout<<endl;


    sum = a+b+c+d+f; // stores the sum of the entries to be used in the denominator. 

    weight = 4.0*a+3.0*b+2.0*c+d; // calculate the weighted sum of the grades (each with their corresponding weight); 
                                  // notice that we assume a 4.0 grading scale.

    gpa = weight/sum; // this divides the weighted sum over the sum of the grades to give the user's gpa.

    cout<<"\n"; // This just seperates the output of the gpa from the prompts the user was given.
    cout<< "Your semester's GPA is: " << gpa <<endl; // display the user's gpa for the semester.



    return 0;
}
