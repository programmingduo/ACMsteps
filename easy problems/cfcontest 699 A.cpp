#include<cstdio>

const long long maxn = (long long)1 << 60;

inline long long min(long long x, long long y)
{
    return x > y? y: x;
}
char dir[200005];
long long a[200005];
int main ()
{
    int n, c;
    scanf("%d ", &c);
    scanf("%s", dir);
    for(int i = 0; i < c; i ++)
    {
        scanf("%I64d", &a[i]);
    }
    long long minate = maxn;

//    printf("%I64d\n", maxn);
    for(int i = 1; i < c; i ++)
    {
        if(dir[i] == 'L' && dir[i - 1] == 'R')
            minate = min(a[i] - a[i - 1], minate);
    }
    if(minate == maxn)
        printf("-1\n");
    else
        printf("%I64d\n", minate / 2);
    return 0;
}
