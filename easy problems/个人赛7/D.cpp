#include<cstdio>

int odd[10007], even[10007], num[10007];

int main ()
{
    odd[1] = 1;
    even[1] = 2;
    num[1] = 1;
    for(int i = 2; i < 10006; i ++)
    {
        odd[i] = 2*i+1 - 2 + odd[i - 1];
        even[i] = even[i - 1] + 2 * i;
        num[i] = i + num[i - 1];
    }
    int t, n, N;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &N);
        printf("%d %d %d %d\n", n, num[N], odd[N], even[N]);
    }
    return 0;
}
