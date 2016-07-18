#include<cstdio>
#include<iostream>

using namespace std;

int main ()
{
    int a;
    string b;
    while(~scanf("%d", &a))
    {
        cin>> b;
        cin>> b;
        if(b[0] == 'w')
            if(a == 5 || a == 6)
                printf("%d\n", 53);
            else
                printf("%d\n", 52);
        else
            if(a == 30)
                printf("%d\n", 11);
            else if(a == 31)
                printf("%d\n", 7);
            else
                printf("%d\n", 12);
    }
    return 0;
}
