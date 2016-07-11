#include<cstdio>
#include<cstring>

int main ()
{
    int num[20];
    memset(num, 0, sizeof(num));
    for(int i = 1; i <= 6; i ++)
        for(int j = 1; j <= 6; j ++)
            for(int k = 1; k <= 6; k ++)
        {
            int temp = i + k + j;
            num[temp] += 1;
        }
    for(int i = 18; i > 0; i --)
        num[i] += num[i + 1];

    int T, a, b;
    scanf("%d", &T);
    double total = 216;
    while(T --)
    {
        scanf("%d%d", &a, &b);
        a += b;
        a = a % 19;
        if(a < 2)
        {
            printf("1.0000\n");
            continue;
        }
        printf("%.4lf\n", 1.0 * num[a] / total);
    }
    return 0;
}
