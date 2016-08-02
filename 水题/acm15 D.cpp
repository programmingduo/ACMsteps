#include<cstdio>

int a[1000], b[1000];

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        for(int j = 0; j < n; j ++)
            scanf("%d", &b[j]);
        int f1= 1, f2 = 1;
        for(int i = 0; i < n; i ++)
        {
            if(a[i] != b[i])
                f1 = 0;
            if(a[i] != b[n - 1 - i])
                f2 = 0;
        }
        if(f1 && f2)
            printf("both\n");
        else if(f1)
            printf("queue\n");
        else if(f2)
            printf("stack\n");
        else
            printf("neither\n");
    }
    return 0;
}
