#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int a)
{
    if(a % 2 == 0)
        return false;
     for(int i = 3; i <= (int)sqrt(a); i += 2)
     {
         if(a % i == 0)
            return false;
     }
     return true;
}

int main ()
{
    int N;
    while(cin>> N)
    {
        int number, prime = 0;
        for(int i = 0; i < N; i++)
        {
            cin>> number;
            if(isPrime(number))
                prime ++;
        }
        cout<< prime<<endl;
    }
    return 0;
}
