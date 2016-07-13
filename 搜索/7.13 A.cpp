#include<cstdio>

int a[] = {0, 0, 1, 1};
int b[] = {0, 1, 0, 1};
int d[4];

char s[100][100];

int main ()
{
    int x, y;
    while(~scanf("%d%d", &x, &y))
    {
        for(int i = 0; i < x; i ++)
        scanf("%s", s[i]);
        int ans = 0;
        for(int i = 0; i < x - 1; i ++)
        {
            for(int j = 0; j < y - 1; j ++)
            {
                for(int k = 0; k < 4; k ++)
                    d[k] = 0;
                for(int k = 0; k < 4; k ++)
                switch(s[i + a[k]][j + b[k]])
                {
                case 'f':
                    d[0] = 1;
                    break;
                case 'a':
                    d[1] = 1;
                    break;
                case 'c':
                    d[2] = 1;
                    break;
                case 'e':
                    d[3] = 1;
                    break;
                }
                int t = 0;
                for(int k = 0; k < 4; k ++)
                    t += d[k];
                if(t == 4)
                    ans ++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
