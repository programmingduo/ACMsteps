#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    string a, b;
    while(cin>>a >> b)
    {
        int total = 0;
        int temp = a.length();
        for(int i = 0; i < temp; i ++)
            if(a[i] == '1')
            total ++;
        total += (total % 2);
        temp = b.length();
        for(int i = 0; i < temp; i ++)
        {
            if(b[i] == '1')
                total --;
        }
        if(total >= 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
