#include<cstdio>

struct Node
{
    int num[6];
    int next;
}node[100005];
int hashtable[1000007], cur;

void init_hash();
int get_hash(int num[]);
int search_hash(int num[]);
void insert_hash(int num[], int h);
int cmp(int num1[], int num2[]);

int main ()
{
    int n, num0[6];
    while(~scanf("%d", &n))
    {
        cur = 0;
        init_hash();
        int temp, twins = 0;
        for(int i = 0; i < n;  i ++)
        {
            for(int j = 0; j < 6; j ++)
            {
                scanf("%d", &temp);
                num0[j] = temp;
            }
            if(twins)
                continue;
            twins = search_hash(num0);
        }
        if(twins)
            printf("Twin snowflakes found.\n");
        else
            printf("No two snowflakes are alike.\n");
    }
    return 0;
}

void init_hash()
{
    for(int i = 0; i < 1000007; i ++)
        hashtable[i] = -1;
    for(int i = 0; i < 100005; i ++)
        node[i].next = -1;
}

int get_hash(int num[6])
{
    int total = 0;
    for(int i = 0; i < 6; i ++)
        total = (total + num[i]) % 1000007;
    return total;
}

int search_hash(int num0[6])
{
    int h = get_hash(num0);
    if(hashtable[h] != -1)
    {
        int t = hashtable[h];
        while(t != -1)
        {
            if(cmp(node[t].num, num0))
                return 1;
            t = node[t].next;
        }
    }
    insert_hash(num0, h);
    return 0;
}

void insert_hash(int num0[6], int h)
{
    node[cur].next = hashtable[h];
    hashtable[h] = cur;
    for(int i = 0; i < 6; i ++)
        node[cur].num[i] = num0[i];
    cur ++;
}

int cmp(int num1[6], int num2[6])
{
    int ans = 1;
    for(int i = 0; i < 6; i ++)
    {
        ans = 1;
        for(int j = 0; j < 6; j ++)
            if(num1[j] != num2[(j + i) % 6])
            ans = 0;
        if(ans)
            return 1;
    }
    for(int i = 0; i < 6; i ++)
    {
        ans = 1;
        for(int j = 0; j < 6; j ++)
            if(num1[j] != num2[(6 - j + i) % 6])
            ans = 0;
        if(ans)
            return 1;
    }
    return 0;
}
