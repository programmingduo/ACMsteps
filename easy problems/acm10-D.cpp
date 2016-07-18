#include<cstdio>

char dir[100005];

int main ()
{
    int t, x1, y1, x2, y2;
    while(~scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2))
    {
        int a = x1 - x2, b = y1 - y2;
        scanf("%s", dir);
        if(a == 0 && b == 0)
        {
            printf("0\n");
            continue;
        }
        int ans = 0;
        for(int i = 0; i < t; i ++)
        {
            if(b > 0 && dir[i] == 'S')
                b --;
            if(a > 0 && dir[i] == 'W')
                a --;
            if(a < 0 && dir[i] == 'E')
                a ++;
            if(b < 0 && dir[i] == 'N')
                b ++;
            if(a == 0 && b == 0)
            {
                ans = i + 1;
                break;
            }
        }
        if(ans)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
}
