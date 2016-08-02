#include<cstdio>
#include<string.h>

char s[1005][1005];
long long a[1005], b[1005];

int main ()
{
    int n, m;
    long long total = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i ++)
        scanf("%s", s[i]);

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(s[i][j] == '*')
                a[i] ++, b[j] ++, total ++;;
//    for(int i = 0; i <n; i ++)
//    printf("%d ", a[i]);
//    printf("\n");
//    for(int i =0; i < m; i ++)
//        printf("%d ", b[i]);
//    printf("\n");
    int flag = 1;
    int x, y;
    for(int i = 0; i < n && flag; i ++)
        for(int j = 0; j < m && flag; j ++)
        if(a[i] + b[j] - (s[i][j] == '*') == total)
        {
//            printf("%d %d\n", i, j);
            flag = 0;
            x = i, y = j;
        }

    if(flag)
        printf("NO\n");
    else
    {
        printf("YES\n");
        printf("%d %d\n", x + 1, y + 1);
    }
    return 0;
}
