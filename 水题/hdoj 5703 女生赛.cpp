#include<cstdio>

int main()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        printf("1");
        n --;
        for(int i = 0; i < n; i ++)
            printf("0");
        printf("\n");
    }
    return 0;
}
