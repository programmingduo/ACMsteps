#include<cstdio>
#include<string.h>

using namespace std;

const int maxn = 500000;
int a[maxn], b[maxn];
//a[i]记录从i翻到的最大页
//b[i]记录i之前翻到的最大页

int main ()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i ++)
    {
        int temp;
        scanf("%d", &temp);
        memset(a, 0, sizeof(a));
        for(int j = 0; j < temp; j ++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if(a[x] < y)
                a[x] = y;
        }

        b[1] = a[1];
        for(int j = 2; j <= temp; j ++)
        {
            if(a[j] > b[j - 1])
                b[j] = a[j];
            else
                b[j] = b[j - 1];
        }

        int count = 0, y = 1;
        while(y <= temp)
        {
            y = b[y] + 1;
            count ++;
        }

        printf("%d\n", count);

    }
    return 0;
}
