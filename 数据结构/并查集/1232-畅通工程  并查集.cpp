#include<iostream>
#include<cstdio>
using namespace std;

void mergeson(int a, int b, int father[]);
int findfather(int a, int father[]);

int main ()
{
    int n;
    while(cin>>n)
    {
        if(n == 0)
            break;
        int father[1005];
        for(int i = 1; i <= n; i ++)
        {
            father[i] = i;                   //传统的初始化方法
        }
        int m;
        scanf("%d", &m);
        for(int i = 1; i <= m; i ++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            mergeson(a, b, father);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(father[i] == i)
                ans ++;
        }
        cout<< (ans - 1)<< endl;
    }
}

void mergeson(int a, int b, int father[])
{
    int tempa = findfather(a, father);
    int tempb = findfather(b, father);
    if(tempa == tempb)
        return ;
    else
        father[father[a]] = tempb;       //这里一定要确定是最后的父亲换成了别人
}

int findfather(int a, int father[])
{
    if(father[a] == a)
        return a;
    father[a] = findfather(father[a], father);  //一个简单的优化
    return father[a];                          //虽然a和fathera是一个东西，但是体现的意义是不一样的
}
