#include<iostream>
#include<cstdio>
using namespace std;
bool record[100006] = {0};
int father[100006];
int findfather(int a)
{
    if(father[a] == a)
        return a;
    int fa = father[a];
    father[a] = findfather(father[a]);          //一个简单的优化
    record[a] = (record[a] + record[fa]) & 1;
    return father[a];
}
void mergeson(int a, int b)
{
    int tempa = findfather(a);
    int tempb = findfather(b);
    if(tempa == tempb)
    {
        return ;
    }
    father[tempb] = tempa;
    record[tempb] = (record[a] - record[b] + 1) & 1;
}
int main ()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        char note;
        bool flag;
        int N, M, n1, n2;
        scanf("%d %d", &N, &M);
        for(int j = 0; j < N; j++)
            father[j] = j;
        for(int j = 0; j < M; j++)
        {
            getchar();
            note = getchar();
            scanf("%d%d",&n1, &n2);
            if(note == 'A')
            {
                if(findfather(n1) == findfather(n2) && record[n1] == record[n2])
                    printf("In the same gang.\n");
                else if(findfather(n1) == findfather(n2) && record[n1] != record[n2])
                    printf("In different gangs.\n");
                else
                    printf("Not sure yet.\n");
            }
            if(note == 'D')
            {
                mergeson(n1, n2);
            }
        }
    }
}
