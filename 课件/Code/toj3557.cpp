/*
与fzu1914极其相似的一个题目
单调队列解决，注意队列长度*2的问题
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 1000006
int t;
char str[maxn];
char str2[maxn];
struct Node
{
    int val;
    int id;
}nd[maxn*2];
int flag1[maxn];
int flag2[maxn];
int sum[maxn];
void solve(char ss[],int ff[])
{
    int len,front,rear,i,tmp;
    if (ss[0] == 'C')
        sum[0] = 1;
    else
        sum[0] = -1;
    len = strlen(ss);
    for (i=1;i<len;i++)
    {
        if (ss[i] == 'C')
            sum[i] = sum[i-1] + 1;
        else
            sum[i] = sum[i-1] - 1;
    }
    front = rear = 0;
    for (i=0;i<len;i++)
    {
        while (front < rear && nd[rear-1].val > sum[i])
            rear--;
        nd[rear].val = sum[i];
        nd[rear].id = i;
        rear++;
    }
    if (nd[front].val >=0 )
        ff[0] = 1;
    for (i=1;i<len;i++)
    {
        tmp = sum[i-1] + sum[len-1];
        while (front < rear && nd[rear-1].val > tmp)
            rear--;
        nd[rear].id = i+len-1;
        nd[rear].val = tmp;
        rear++;
        while (front < rear && nd[front].id < i)
            front++;
        tmp = nd[front].val;
        if (tmp >= sum[i-1])
            ff[i] = 1;
    }
    return;
}
int main()
{
    int i,ans,len,cs;
    while (scanf("%d",&t)!=EOF)
    {
        cs = 1;
        while (t--)
        {
            ans = 0;
            scanf("%s",str);
            len = strlen(str);
            memset(flag1,0,sizeof(flag1));
            memset(flag2,0,sizeof(flag2));
            solve(str,flag1);
            for (i=0;i<len-2-i;i++)
                swap(str[i],str[len-2-i]);
            solve(str,flag2);
            for (i=0;i<len;i++)
            {
                if (flag1[i]||flag2[len-i-1])
                    ans++;
            }
            printf("Case %d: %d\n",cs++,ans);
        }
    }
    return 0;
}
