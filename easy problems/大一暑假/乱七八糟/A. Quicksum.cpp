#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;

int main ()
{
    char s[260];
    while(1)
    {
        gets(s);
        if(s[0] == '#')
            break;
        int i = 0, ans = 0;
        while(s[i])
        {
            if(s[i] != ' ')
            {
                ans += (s[i] - 'A' + 1) * (++ i);
            }
            else
                i ++;
        }
        cout<< ans<< endl;
    }
}
