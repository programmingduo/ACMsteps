#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main ()
{
    int T;
    string a, b;
    scanf("%d", &T);
    while(T --)
    {
        cin>> a>> b;
        int flag = 0;
        int la = a.length(), lb = b.length();
        for(int i = 0, j = 0; i < la || j < lb; i ++, j ++)
        {
            if(i == la - 1 && j == la - 1)
            {
                if(a[i] == b[j])
                    flag = 1;
                break;
            }
            else if(i == la - 1)
            {
                for(int k = j; k < lb; k ++)
                {
                    if(b[k] !=b[k - 1])
                }
            }
            if(a[i] != b[j])
            {
                if(i != 0 && a[i] == a[i - 1])
                {
                    j --;
                    continue;
                }
                if(j != 0 && b[j] == b[j - 1])
                {
                    i --;
                    continue;
                }
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
