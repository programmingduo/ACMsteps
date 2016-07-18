#include<cstdio>

int main ()
{
    int s, d;
    while(~scanf("%d%d", &s, &d))
    {
        int ans = 0;
        if(d > s * 4)
            ans = 10 * s - d * 2;
        else if(d * 2 > s * 3)
            ans = 8 * s - d * 4;
        else if(d * 3 > s * 2)
            ans = 6 * s - d * 6;
        else if(d * 4 > s)
            ans = 3 * s - d * 9;
        else
            ans = -1;

        if(ans <= 0)
            printf("Deficit\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
