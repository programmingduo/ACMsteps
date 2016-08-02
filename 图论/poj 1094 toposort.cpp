#include<cstdio>
#include<string.h>

int map[30][30], indegree[30];
char ans[30];

int toposort(int n)
{
    int temp[30], flag = 1;
    for(int i = 1; i <= n; i ++)
        temp[i] = indegree[i];
    for(int i = 0; i < n; i ++)
    {
        int m = 0, loc;
        for(int j = 1; j <= n; j ++)
            if(temp[j] == 0)
                m ++, loc = j;
        if(m == 0)
        {
            for(int j = 1; j <= n; j ++)
                if(temp[j] > 0)
                return 0;
        }
        if(m > 1)
            flag = -1;
        //不能直接返回。可能在处理之后发现有环
        //当一个拓扑排序既不能确定顺序又有环的时候应该返回有环而不是无法确定
        for(int j = 1; j <= n; j ++)
        {
            if(map[loc][j])
            {
                temp[j] --;
            }
        }
        temp[loc] = -1;
        ans[i] = loc - 1 + 'A';
    }
    return flag;
}

int main ()
{
    int n, m, a, b, flag;
    char temp[5];
    while(~scanf("%d%d", &n, &m))
    {
        if(n == 0 && m == 0)
            break;
        flag = 0;
        memset(map, 0, sizeof(map));
        memset(indegree, 0, sizeof(indegree));
        for(int i = 1; i <= m; i ++)
        {
            scanf("%s", temp);
            if(flag)
                continue;
            a = temp[0] - 'A' + 1;
            b = temp[2] - 'A' + 1;
            map[a][b] = 1;
            indegree[b] ++;
            int s = toposort(n);
            if(s == 1)
            {
                printf("Sorted sequence determined after %d relations: ", i);
                for(int j = 0; j < n; j ++)
                    printf("%c", ans[j]);
                printf(".\n");
                flag = 1;
            }
            if(s == 0)
            {
                printf("Inconsistency found after %d relations.\n", i);
                flag = 1;
            }
        }
        if(!flag)
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
