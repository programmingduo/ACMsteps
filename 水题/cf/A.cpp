#include<cstdio>

int n, flag;
char s[500000][6];

int main ()
{
    scanf("%d", &n);
    flag = 0;
    for(int i = 0; i  < n; i ++)
    {
        scanf("%s", s[i]);
    }
    for(int i = 0; i < n; i ++)
    {
        if(s[i][0] == s[i][1] && s[i][0] ==  'O')
        {
            s[i][0] = s[i][1] = '+';
            flag = 1;
            break;
        }
        if(s[i][3] == s[i][4] && s[i][3] == 'O')
        {
            s[i][3] = s[i][4] = '+';
            flag = 1;
            break;
        }
    }
    if(flag )
    {
    printf("YES\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", s[i]);
    }
    }

    else
        printf("NO\n");

    return 0;
}
