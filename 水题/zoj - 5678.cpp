#include<cstdio>

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int a[4], total = 0;
        for(int i = 0; i < 4; i ++)
            scanf("%d", &a[i]);
        for(int i = 0; i < 4; i ++)
            total += a[i];
        if(total >= 80)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
