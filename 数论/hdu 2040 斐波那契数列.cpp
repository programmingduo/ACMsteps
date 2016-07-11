#include<cstdio>
#include<string.h>

int ans[60];

int compute(int n)
{
    if(n <= 1)
        return 1;
    if(ans[n])
        return ans[n];
    return ans[n] = compute(n - 1) + compute(n - 2);

}

int main ()
{
    int T, M;
    memset(ans, 0, sizeof(ans));
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &M);
        printf("%d\n", compute(M - 1));
    }
    return 0;
}
