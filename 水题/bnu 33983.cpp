#include<cstdio>

int main ()
{
    int n, a;
    while(~scanf("%d", &n))
    {
        int maxx = -0x3fffffff, maxid;
        int minn = 0x3fffffff, minid;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a);
            if(maxx < a)
            {
                maxx = a;
                maxid = i;
            }
            if(minn > a)
            {
                minn = a;
                minid = i;
            }
        }
        printf("%d %d\n", minn, minid);
        printf("%d %d\n", maxx, maxid);
    }
    return 0;
}
