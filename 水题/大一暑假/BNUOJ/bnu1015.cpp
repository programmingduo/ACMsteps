#include<stdio.h>
#include<string>
#include<cstring>

using namespace std;

char ans[205][205], inp[400005];

int main ()
{
    int m, n;
    scanf("%d%d", &n, &m);
    getchar();
    while(gets(inp))
    {
        int len = 0;
        int temp = strlen(inp);              //省去了调用函数的时间，很有用
        for(int i = 0; i < temp; i ++)
        {
            if((inp[i] <= 'z' && inp[i] >='a') || (inp[i] <= 'Z' && inp[i] >= 'A'))
            {
                inp[i] = toupper(inp[i]);
                ans[len / m][len % m] = inp[i];
                len ++;
            }
        }

        int total = 0;
        while(len < n * m)
        {
            ans[len / m][len % m] = 'A' + total % 26;
            total ++;
            len ++;
        }

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
            printf("%c", ans[j][i]);

        printf("\n");
    }
    return 0;
}
