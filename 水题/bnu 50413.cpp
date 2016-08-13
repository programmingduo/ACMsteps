#include<cstdio>
#include<cstring>
char s[100];

int main ()
{
    gets(s);
    int len = strlen(s);
    for(int i = 0; i < len; i ++)
    {
        if(s[i] <= 'z' && s[i] >= 'a')
            s[i] += 'A' - 'a';
        else if(s[i] <= 'Z' && s[i] >= 'A')
            s[i] += 'a' - 'A';
    }
    printf("%s\n",s);
    return 0;
}
