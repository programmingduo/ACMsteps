#include<iostream>

using namespace std;

int GCD(int a, int b)
{
    if(a > b)
        return GCD(b, a);
    if(b % a == 0)
        return a;
    else
        return GCD(a, b % a);
}

int main ()
{
    int N;
    cin>> N;
    for(int i = 0; i < N; i ++)
    {
        int a, b, c;
        cin>> a>>b;
        int d = a / b;
        if(d % 2 != 0)
        {
            cout<< b * 2<< endl;
            continue;
        }
        for(int j = 3; ; j += 2)
        {
            if(GCD(j, d) == 1)
            {
                cout<< b * j<< endl;
                break;
            }
        }
    }
    return 0;
}
