#include<iostream>
#include<cmath>
#include<iomanip>
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

int findNumber(int low, int high, int mid, int n)
{
    if(low + 1 == high)
    {
        if(prime[high].primeNumber == n)
            return high;
        if(prime[low].primeNumber == n)
            return low;
    }
    if(prime[mid].primeNumber == n)
        return mid;
    else if(prime[mid].primeNumber > n)
        return findNumber(low, mid, (low + mid) / 2, n);
    else
        return findNumber(mid, high, (mid + high) / 2, n);
}

int findNumber(int n)
{
    int low = 0, high = n - 1, mid = (low + high) / 2;
    return findNumber(low, high, mid, n);
}

int findFactor(int n, int i)
{
    if(n == 1)
        return i;
    for()
}

int main()
{
    int n;
    findingPrime(1000003);
    while(cin>> n)
    {
        int i = 1;
        while(n % 2 == 0)
        {
            i = 2;
            n /= 2;
        }
        i = findFactor(n, i);
        int x = findNumber(i);
        cout<< x<< endl;
    }
    return 0;
}
