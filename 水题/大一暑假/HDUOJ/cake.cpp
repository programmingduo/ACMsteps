#include<iostream>

using namespace std;

int GCD(int a, int b)
{
    if(a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int ans;
    while(a != 0)
    {
        int m = b % a;
        b = a;
        a = m;
    }
    return b;
}

int main()
{
    int p, q;
    while(cin>> p>> q)
    {
        if(p > q)
        {
            int a = q;
            q = p;
            p = a;
        }
        int ans = q + p - GCD(q % p, p);
        cout<< ans<< endl;
    }
}
