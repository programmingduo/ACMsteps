#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main ()
{
    int T;
    while(~scanf("%d", &T))
    {
        int temp = sqrt(T), ans = 0;
        for(int i = 2; i <= temp;  i++)
            if(T % i == 0)
        {
            cout<< i<< endl;
            ans ++;
            while(T % i == 0)
            {
                T /= i;
            }
        }
        if(T != 1)
            ans ++;
        cout<< ans<< endl;
    }
}
