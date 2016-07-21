#include<cstdio>
#include<string.h>

int suma[100005][26], sumb[26], ans[100005];
char a[100005], b[100005];

int main ()
{
    int T, n, m;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &n, &m);
        scanf("%s", a + 1);
        scanf("%s", b + 1);

        for(int i = 0; i < 26; i ++)
            suma[0][i] = 0, sumb[i] = 0;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 0; j < 26; j ++)
                suma[i][j] = suma[i - 1][j];
            suma[i][a[i] - 'a'] ++;
        }
        for(int i = 1; i <= m; i ++)
        {
            sumb[b[i] - 'a'] ++;
        }

        memset(ans, 0, sizeof(ans));
        int flag = 0 , no = 0;
        char last;
        for(int i = 1, j = 1; i <= n, j <= m; i ++)
        {
            if(j == 1 && i + m > n + 1)
                break;
            if(j == 1)
            {
                for(int k = 0; k < 26 && !no; k ++)
                {
                    if(suma[i + m - 1][k] - suma[i - 1][k] != sumb[k])
                        no = 1;
                }
                if(no)
                {
                    no = 0;
                    continue;
                }
            }
            if(flag)
            {
                flag = 0;
                if(a[i] == last)
                {
                    j ++;
                }
                else
                {
                    i = i - j + 1;
                    j = 1;
                    continue;
                }
            }
            else
            {
                if(a[i] == b[j])
                {
                    j ++;
                }
                else
                {
                    if(j == m || a[i] != b[j + 1])
                    {
                        i = i - j + 1;
                        j = 1;
                        continue;
                    }
                    else
                    {
                        j ++;
                        flag = 1;
                        last = b[j - 1];
                    }
                }
            }
            if(j > m)
            {
                ans[i - m + 1] = 1;
                i = i - m + 1;
                j = 1;
            }
        }

        for(int i = 1; i <= n; i ++)
        {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}
