#include<iostream>
#include<string.h>
#include<string>
#include<cstdio>

using namespace std;

int ans[1005][1005];
int main()
{
    string a, b;
    int k;
    while(cin>> a>> b)
    {
        memset(ans, 0, sizeof(ans));
        while(a.length() > 1000 || b.length() > 1000)
            k ++;
        int la = a.length(), lb = b.length(), p = 0;
        for(int i = 1; i <= la; i ++)
        {
            for(int j = 1; j <= lb; j ++)
            {
                ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
                if(a[i - 1] == b[j - 1])
                {
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                }
                if(ans[i][j] > p)
                    p = ans[i][j];
            }
        }
        printf("%d\n", p);
    }
    return 0;
}
