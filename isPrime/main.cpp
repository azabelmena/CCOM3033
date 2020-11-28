#include <iostream>
#include<cmath>

using namespace std;

bool isPrime(int);

int main()
{
    int num;
    bool isprime = false;

    cout<< "Enter a positive integer: ";
    cin>> num;

    isprime=isPrime(num);

    if(isprime){
        cout<< num << " is a prime number." <<endl;
    }
    else{
        cout<< num << " is not a prime number." <<endl;
    }


    return 0;
}

bool isPrime(int num){

    int root = sqrt(num);
    bool prime = true;

    if(num==1){
        prime = false;

        return prime;
    }

    for(int d = 2; d <= root; d++){
        if(num%d==0){
            prime = false;

            return prime;
        }
    }

    return prime;
}
