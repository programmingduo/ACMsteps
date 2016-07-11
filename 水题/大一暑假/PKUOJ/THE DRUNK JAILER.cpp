#include<stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    while(N --)
    {
        bool open[101] = {false};
        int n;
        scanf("%d", &n);
        for(int j = 1; j <= n; j ++)
        {
            for(int i = 1; i * j <= n; i ++)
                open[i * j] = !open[i * j];
        }
        int sum = 0;
        for(int i = 1; i <= n; i ++)
            if(open[i])
            sum ++;
        printf("%d\n", sum);
    }
    return 0;
}
