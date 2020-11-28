#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
	string firstName, lastName;
	int age;

	cout<< "Enter your first name: ";
		cin>>firstName;
	cout<< "Enter your last name: ";
		cin>>lastName;
	cout<<"Your full name is: " << firstName << " " << lastName <<endl;

	cout<<"Enter your age: ";
		cin>> age;
	cout<< "Your age is: "<< age <<endl;

	return 0;


}
