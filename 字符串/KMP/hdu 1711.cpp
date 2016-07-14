#include<cstdio>

int a[1000005], b[10005], next[10005];
int n, m;

void get()
{
    next[0] = next[1] = 0;
    for(int i = 2; i < m; i ++)
    {
        int j = next[i - 1];
        while(j && b[i - 1] != b[j])
            j = next[j];
        next[i] = b[i - 1] == b[j] ? j + 1: 0;
    }
}

int search()
{
    int j = 0, i = 0;
    for(; i < n; i ++)
    {
        if(j == m)
            break;
        if(b[j] == a[i])
            j ++;
        else
        {
            while(b[j] != a[i] && j)
                j = next[j];
            if(b[j] == a[i])
                j ++;
        }
    }
    if(j == m)
        return i - m + 1;
    return -1;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        for(int j = 0; j < m; j ++)
            scanf("%d", &b[j]);

        get();
        int ans = search();
        printf("%d\n", ans);
    }
    return 0;
}
