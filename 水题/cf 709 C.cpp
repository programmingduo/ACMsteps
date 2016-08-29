#include<cstdio>
#include<cstring>

char s[100005];

int main ()
{
    scanf("%s", s);
    int len = strlen(s), flag = 0;
    for(int i = 0; i < len; i ++)
    {
        if(s[i] == 'a')
        {
            if(!flag)
            {
                continue;
            }
            break;
        }
        flag = 1;
        s[i] = s[i] - 1;
    }
    if(!flag)
        s[len - 1] = 'z';
    printf("%s\n", s);
}
