#include<cstdio>
#include<string.h>

int a[105][105], hang[105], lie[105];

int main ()
{
    int n;
    while(~scanf("%d", &n) && n != 0)
    {
        int ansh, ansl, totall = 0, totalh = 0;
        memset(hang, 0, sizeof(hang));
        memset(lie, 0, sizeof(lie));
        for(int i = 0; i <n; i ++)
        {
            for(int j = 0; j < n; j ++)
                scanf("%d", &a[i][j]);
        }

        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j ++)
                hang[i] += a[i][j];
        }

        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j ++)
                lie[i] += a[j][i];
        }

        for(int i = 0; i < n; i ++)
        {
            if(hang[i] % 2 == 1)
            {
                ansh = i;
                totalh ++;
            }
            if(lie[i] % 2 == 1)
            {
                ansl = i;
                totall ++;
            }
        }

        if(totalh == 0 && totall == 0)
            printf("OK\n");
        else if(totalh == 1 && totall == 1)
        {
            printf("Change bit (%d,%d)\n", ansh + 1, ansl + 1);
        }
        else
            printf("Corrupt\n");
    }
    return 0;
}
