#include<cstdio>

int main ()
{
    int n, s, m, flag;
    while(~scanf("%d", &n) && n)
    {
        m = 1;
        while(++ m)
        {
            s = 0, flag = 1;
            for(int i = n; i >= 2; i --)
            {
                s = (s + m + i - 1) % i;
                if(s == 0 && i != 2)
                {
                    flag = 0;
                    break;
                }
            }
            if(s == 0 && flag)
            {
                printf("%d\n", m);
                break;
            }
        }
    }
}
