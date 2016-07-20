#include<cstdio>
#include<string.h>

int a[2000005];
int vis[2000005], fix[2000005];
int root = -1, ans;

void dfs(int index)
{
//printf("%d ", index);
    if(fix[index])
        return ;
    if(vis[index] && root == -1)
    {
//        printf("\n1\n");
        root = index;
        fix[index] = 1;
        ans ++;
        a[index] = index;
        return ;
    }
    else if(vis[index])
    {
//        printf("\n2\n");
        a[index] = root;
        fix[index] = 1;
        ans ++;
        return ;
    }
    vis[index] = 1;

    if(a[index] == index && index != root)
    {
//        printf("root: %d %d\n", index, root);
        if(root == -1)
        {
            root = index;
            fix[index] = 1;
        }
        else
        {

//        printf("\n3\n");
            a[index] = root;
            ans ++;
        }

        vis[index] = 0;
        return ;
    }
    else if(a[index] == index)
    {
        vis[index] = 0;
        return ;
    }

    dfs(a[index]);
    fix[index] = 1;
    vis[index] = 0;
}

int main ()
{
    int n, flag;
    scanf("%d", &n);
    memset(fix, 0, sizeof(fix));

    root = -1;
    ans = 0;
    flag = 1;
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", a + i);
        if(a[i] == i)
            root = i;
    }

    for(int i = 1; i <= n; i ++)
    {
        if(fix[i])
            continue;
        dfs(i);
    }

    printf("%d\n", ans);
    for(int i = 1; i <= n; i ++)
    {
        if(i > 1)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
