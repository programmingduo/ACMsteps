#include<cstdio>
#include<cstring>

int next[200000];
char s1[50004], s2[50004], s[100005];

void get_next(char *c)
{
    int len = strlen(c);
    next[0] = next[1] = 0;
    for(int i = 2; i <= len ; i ++)
    {
        int j = next[i - 1];
        while(j && c[i - 1] != c[j])
            j = next[j];
        next[i] = c[i - 1] == c[j]? j + 1: 0;
    }
}

int main()
{
    while(~scanf("%s %s", s1, s2))
    {
        strcat(s1, "*");
        strcat(s1, s2);
        get_next(s1);
        int len = next[strlen(s1)];
        for(int i = 0; i < len; i ++)
            printf("%c", s1[i]);
        if(len)
            printf(" ");
        printf("%d\n", len);
    }
}
