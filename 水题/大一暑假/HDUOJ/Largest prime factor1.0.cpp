#include<iostream>
#include<cmath>

using namespace std;

struct node
{
    int primeNumber;
    int id;
}prime[100004];

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
    int i = 0, number = 1;
    for(; number <= 2; number ++, i ++)
    {
        prime[i].primeNumber = number;
    }
    for(; number <= n; number += 2)
    {
        if(isPrime(number))
        {
            prime[i ++].primeNumber = number;
        }
    }
    return ;
}
