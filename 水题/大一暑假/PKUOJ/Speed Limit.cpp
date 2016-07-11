#include<stdio.h>

int main ()
{
    int N;
    while(scanf("%d", &N))
    {
        if(N == -1)   break;
        int s[15], t[15], mile;
        for(int i = 0; i < N; i ++)
        {
            scanf("%d %d", &s[i], &t[i]);
        }
        mile = s[0] * t[0];
        for(int i = 1; i < N; i ++)
        {
            mile += s[i] * (t[i] - t[i - 1]);
        }
        printf("%d miles\n", mile);
    }
    return 0;
}
