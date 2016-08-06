#include<cstdio>

int B[6][24]={ {6,1,12,3,5,11,16,7,8,9,4,10,18,13,14,15,20,17,22,19,0,21,2,23}, //ok
               {20,1,22,3,10,4,0,7,8,9,11,5,2,13,14,15,6,17,12,19,16,21,18,23}, //ok
               {1,3,0,2,23,22,4,5,6,7,10,11,12,13,14,15,16,17,18,19,20,21,9,8}, //ok
               {2,0,3,1,6,7,8,9,23,22,10,11,12,13,14,15,16,17,18,19,20,21,5,4}, //ok
               {0,1,8,14,4,3,7,13,17,9,10,2,6,12,16,15,5,11,18,19,20,21,22,23}, //ok
               {0,1,11,5,4,16,12,6,2,9,10,17,13,7,3,15,14,8,18,19,20,21,22,23}  //ok
              };

int ans;

int one(int *x, int a, int b, int c, int d)
{
    if(x[a] == x[b] && x[b] == x[c] && x[c] == x[d])    return 1;
    return 0;
}
int now(int *x)
{
    int ret = 0;
    if(one(x, 0,1,2,3))     ret ++;
    if(one(x, 4,5,10,11))   ret ++;
    if(one(x, 6,7,12,13))   ret ++;
    if(one(x, 8,9,14,15))   ret ++;
    if(one(x, 16,17,18,19)) ret ++;
    if(one(x, 20,21,22,23)) ret ++;

    return ret;
}

int max(int x, int y)
{
    return x> y? x:y;
}

void dfs(int *x, int n)
{
    ans = max(ans, now(x));
    if(n == 0)
        return ;
    int temp[24];
    for(int i = 0; i < 6; i ++)
    {
        for(int j = 0; j < 24; j ++)
        {
            temp[j] = x[B[i][j]];
        }
        dfs(temp, n - 1);
    }
}

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        int a[30];
        for(int i = 0; i < 24; i ++)
        {
            scanf("%d", &a[i]);
        }

        ans = 0;
        dfs(a, n);
        printf("%d\n", ans);
    }
    return 0;
}
