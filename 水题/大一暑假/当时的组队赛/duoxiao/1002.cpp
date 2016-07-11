#include<cstdio>
#include<algorithm>

using namespace std;

int a[1000006];

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n;
        scanf("%d", &n);
        if(n == 1)
        {
            scanf("%d", &a[0]);
            printf("0\n");
            continue;
        }
        if(n == 2)
        {
            for(int i = 0; i < n; i ++)
                scanf("%d", &a[i]);
            printf("%d\n", n);
            continue;
        }

        scanf("%d%d", &a[0], &a[1]);
        int lencha = 2, lenbi = 2, maxcha = 2, maxbi = 2;
        for(int i = 2; i < n; i ++)
        {
            scanf("%d", &a[i]);
            if(a[i] * a[i - 2] == a[i - 1] * a[i - 1] && a[i] * a[i - 2] != 0)
            {
                lenbi ++;
                maxbi = max(maxbi, lenbi);
            }
            else
            {
                lenbi = 2;
            }
            if(a[i] + a[i - 2] == 2 * a[i - 1])
            {
                lencha ++;
                maxcha = max(maxcha, lencha);
            }
            else
            {
                lencha = 2;
            }
        }
        printf("%d\n", max(maxcha, maxbi));

    }

}
