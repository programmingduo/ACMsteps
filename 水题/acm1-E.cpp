#include<cstdio>

int main ()
{
    int N, a[3], ans, temp, nomal, flag, c;
    scanf("%d", &c);
    while(c --)
    {
        scanf("%d", &N);
        flag = 0;
        scanf("%d%d%d", &a[0], &a[1], &a[2]);
        if(a[0] == a[1] || a[0] == a[2])
        {
            nomal = a[0];
        }
        else
        {
            flag = 1;
            nomal = a[1];
            ans = a[0];
        }
        if(!flag)
        {
            if(a[1] != a[0])
            {
                flag = 1;
                ans = a[1];
            }
            else if(a[2] != a[0])
            {
                flag = 1; ans = a[2];
            }
        }

        for(int i = 3; i < N; i ++)
        {
            scanf("%d", &temp);
            if(!flag && temp != nomal)
            {
                flag = 1;
                ans = temp;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
