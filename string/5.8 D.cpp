#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

char c[200];
int n;

int main ()
{
    string hex;
    while(cin>> hex)
    {
        int len = hex.length(), temp = 0;
        n = 0;
        for(int i = 0; i < len; i ++)
        {
            if(hex[i] <= '9' && hex[i] >= '0')
                temp = (hex[i] - '0') * 16;
            else
                temp = (hex[i] - 'A' + 10) * 16;
            i ++;
            if(hex[i] <= '9' && hex[i] >= '0')
                temp += (hex[i] - '0');
            else
                temp += (hex[i] - 'A' + 10);
//            printf("%d ", temp);
            c[n ++] = temp;
        }
        for(int i = 0; i < n; i ++)
            printf("%c", c[i]);
        printf("\n");
    }
    return 0;
}
