//this program calculates the user's gross pay.
#include<iostream>
using namespace std;

int main(){
  double hours, rate, pay;
  cout<< "How many hours did you work? "; //ask the user how many hours they work.
  cin >> hours;

  cout<< "How much do you get paid per hour? "; //ask the user their pay rate.
  cin >> rate;

  pay = hours*rate; //calculate the gross pay.

  //dispaly the user's gross pay.

  cout<< "Your gross pay is: $" << pay <<endl;

  return 0;
}


/*
Psuedo code of this program would look like:

ask howmamy hours worked
input hours

ask for payrate
input rate

pay = hours * rate

display pay
*/
