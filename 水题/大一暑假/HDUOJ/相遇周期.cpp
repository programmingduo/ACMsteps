#include<iostream>
#include<cmath>

using namespace std;

int GCD(int a, int b)
{
    if(a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
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
    int N;
    cin>> N;
    while(N --)
    {
        long long t1, t2, n1, n2, temp;
        char a;
        cin>> n1>> a>> t1>> n2>> a>> t2;
        temp = GCD(n1, t1);
        if(temp != 1)
        {
            n1 /= temp;
            t1 /= temp;
        }
        temp = GCD(n2, t2);
        if(temp != 1)
        {
            n2 /= temp;
            t2 /= temp;
        }
        long long fenzi = t1 * t2, fenmu = abs(t1 * n2 - t2 * n1);
        temp = GCD(fenzi, fenmu);
        if(temp != 1)
        {
            fenzi /= temp;
            fenmu /= temp;
        }
        if(fenmu == 1)
            cout<< fenzi<<endl;
        else
            cout<< fenzi<< "/"<< fenmu<< endl;
    }
}
