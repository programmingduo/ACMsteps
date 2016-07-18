#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

struct
{
    char DNA[10];
    int length;
    int stored;
}node[10];

char DNA[10][10];
char jianji[5] = {'A', 'G', 'C', 'T'};
int squences, deep;

int dfs(int step)              //ֻ�Ƿ�����û�гɹ������ͨ��ȫ�ֱ�����Ӧ
{
    int maxn = 0;
    for(int i = 0; i < squences; i ++)
    {
        maxn = max(maxn, node[i].length - node[i].stored);
    }
    if(step + maxn > deep)
        return 0;
    if(maxn == 0)
        return 1;
    for(int i = 0; i < 4; i ++)
    {
        int temp[10], flag = 0;
        for(int j = 0; j < squences; j ++)
            temp[j] = node[j].stored;
        for(int j = 0; j < squences; j ++)
        {
            if(node[j].DNA[node[j].stored] == jianji[i])
            {
                flag = 1;
                node[j].stored ++;
            }
        }
        if(flag)
        {
            if(dfs(step + 1))
                return 1;
            for(int j = 0; j < squences; j ++)
                node[j].stored = temp[j];
        }
    }
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);   //��һ��֪��ԭ��string����C�Ļ����������ͣ�û�취ֱ���������
    while(N --)        //�����жϷ���
    {
        scanf("%d", &squences);
        for(int i = 0; i < squences; i ++)
        {
            scanf("%s", &(node[i].DNA));
            for(int j = 0; node[i].DNA[j] != '\0'; j ++)
                node[i].length = j + 1;
            //node[i].length = node[i].DNA.length();
            node[i].stored = 0;
        }
        deep = node[0].length;
        while(!dfs(0))
            deep ++;

        printf("%d\n", deep);
    }
    return 0;
}
