#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

bool isPrime(int number)
{
    if(number % 2 == 0)
        return 0;
    for(int i = 3; i <= sqrt(number); i += 2)
        if(number % i == 0)
            return 0;
    return 1;
}

void findingPrime(int n)
{

    cout<< setprecision(7);
    int i = 0, number = 1;
    for(; number <= 2; number ++, i ++)
    {
        cout<< number<< " "<< i<< endl;
    }
    for(; number <= n; number += 2)
    {
        if(isPrime(number))
        {
            cout<< number<< " "<< i<< endl;
            i ++;
        }
    }
    return ;
}

int main ()
{
    int n;
    while(cin>> n)
    findingPrime(n);

    return 0;
}
