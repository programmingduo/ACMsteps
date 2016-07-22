#include<cstdio>
#include<string.h>

using namespace std;

#define MAXSIZE 500005

typedef struct
{
    int left, right;
}NODE;

int     n, m ;
int     num [MAXSIZE], sum[MAXSIZE];
NODE    tree[MAXSIZE * 4] ;

void build(int root, int left, int right)
{
    tree[root].left = left;
    tree[root].right = right;
    if(left == right)
    {
        //printf("return \n");
        sum[root] = num[left];
        return ;
    }

    int mid = (left + right) / 2;
    //printf("left = %d right = %d mid = %d\n", left, right, mid);
    build(root * 2, left, mid);
    build(root * 2 + 1, mid + 1, right);
    sum[root] = sum[root * 2] + sum[root * 2 + 1];
}

void add(int root, int pos, int value)
{
    sum[root] += value;
    if(tree[root].left == tree[root].right)
    {
        return ;
    }

    if(tree[root * 2].right >= pos)
        add(root * 2, pos, value);
    else
        add(root * 2 + 1, pos, value);
}

int query(int root, int left, int right)
{
    if(tree[root].left == left && tree[root].right == right)
        return sum[root];

    int mid = tree[root].left + tree[root].right;
    mid /= 2;
    if(mid >= right)
        return query(root * 2, left, right);
    else if(mid < left)
        return query(root * 2 + 1, left, right);

    return query(root * 2, left, mid) + query(root * 2 + 1, mid + 1, right);
}

int main ()
{
    int T;
    scanf("%d", &T);
    for(int k = 1; k <= T; k ++)
    {
        int N;
        scanf("%d", &N);
        for(int j = 1; j <= N; j ++)
        {
            scanf("%d", &num[j]);
        }
        build(1, 1, N);
        char a[10];
        int i, j;
        int flag = 1;
        while(1)
        {
            scanf("%s", a);
            if(strcmp(a, "End") == 0)
                break;

            scanf("%d%d", &i, &j);
            if(strcmp(a, "Add") == 0)
                add(1, i, j);
            else if(strcmp(a, "Sub") == 0)
                add(1, i, -j);
            else if(strcmp(a, "Query") == 0)
            {
                if(flag)
                {
                    printf("Case %d:\n", k);
                    flag = 0;
                }
                int ans = query(1, i, j);
                printf("%d\n", ans);
            }
        }
    }
}
