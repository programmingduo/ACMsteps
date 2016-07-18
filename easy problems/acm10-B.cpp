#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main ()
{
    int n, begain ,end;
    string str;
    while(~scanf("%d", &n))
    {
        cin>> str;
        for(int i = 0; ; i ++)
            if(str[i] != '.')
        {
            begain = i;
            break;
        }
        for(int i = begain; ; i ++)
        {
            if(str[i] != str[begain])
            {
                end = i;
                break;
            }
        }
        if(str[end] == '.' && str[begain] == 'L')
            printf("%d %d\n", end, begain);
        else if(str[end] == '.' && str[begain] == 'R')
            printf("%d %d\n", begain + 1, end + 1);
        else
        printf("%d %d\n", begain + 1, end);
    }
    return 0;
}
