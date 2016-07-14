#include<cstdio>
#include<cstring>

char s1[100006], s2[100006];
int next1[100006], next2[100006];
int diviser1[100006], diviser2[100006];

void getNext(char * a, int *na)
{
    int len = strlen(a);
    na[0] = na[1] = 0;
    for(int i = 2; i < len; i ++)
    {
        int j = na[i - 1];
        while(j && a[i - 1] != a[j])
            j = na[j];
        na[i] = a[i - 1] == a[j] ? j + 1: 0;
    }
}

void getDiviser(char *a, int *na, int& d)
{
    int len = strlen(a);
    if(len % (len - na[len])) == 0)
        d = len - na[len];
    else
        d = len;
}

int cmp(int l1)
{
    for(int i = 0; i < l1; i ++)
        if(s1[i] != s2[i])
        return 1;
    return 0;
}

int main ()
{
    root = new node();
    while(~scanf("%s%s", s1, s2))
    {
        root->clean();
        root->val = 2;
        int d1 = 0, d2 = 0, ans = 0;
        getNext(s1, next1);
        getNext(s2, next2);
        for(int i = 0; i < strlen(s1); i ++)
            printf("%d ", next1[i]);
        printf("\n");
        for(int i = 0; i < strlen(s2); i ++)
            printf("%d ", next2[i]);
        printf("\n");

        getDiviser(s1, next1, d1);
        getDiviser(s2, next2, d2);
//        printf("sfad");
        if(d1 != d2 || cmp(d1) != 0)
        {
            printf("0\n");
            continue;
        }

    }
    return 0;
}
