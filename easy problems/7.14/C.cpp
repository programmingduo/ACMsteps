#include<cstdio>
#include<cstring>

int min (int a, int b)
{
    return a< b? a: b;
}

char s[100005];

int main ()
{
    int a[2];
    while(~scanf("%s", s))
    {
        int l = strlen(s);
        a[0] = a[1] = 0;
        for(int i = 0; i < l; i ++)
        {
            a[s[i] - '0'] ++;
        }
        printf("%d\n", min(a[0], a[1]));
    }
    return 0;
}
