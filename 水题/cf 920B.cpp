#include <iostream>
#include <cstdio>
#include <cstdlib>

int l[1003], r[1004];

int main()
{
    int T, N;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &N);
        for(int i = 1; i <= N; i ++)
        {
            scanf("%d %d", &l[i], &r[i]);
        }

        int flag = 0;
        for(int i = 1, time = 1; i <= N; i ++)
        {
            if(l[i] > time)
            {
                time = l[i --];
            }
            else if(r[i] < time)
            {
                if(flag)
                    printf(" ");
                printf("0");
                flag = 1;
            }
            else
            {
                if(flag)
                    printf(" ");
                printf("%d", time ++);
                flag = 1;
            }
        }
        printf("\n");
    }
}
