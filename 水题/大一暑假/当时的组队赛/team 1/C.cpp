#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

struct node{
    int num[2000];
    int g;
}a[10010];

long long int f=1000000007;

void cheng(int t, int m)  //大数乘以小数
{
    int k = 0;
    for(int i = 0; i < a[t-1].g; i ++)
    {
        a[t].num[i]=a[t-1].num[i]*m+k;
        k=a[t].num[i]/10000;
        a[t].num[i]%=10000;
    }

    a[t].g=a[t-1].g;
    while(k)
    {
        a[t].num[a[t].g]=k%10000;
        k/=10000;
        a[t].g++;
    }
}
void chu(int t,int m)  //大数除以小数
{
    long long int k=0;
    for(int i=a[t].g-1;i>=0;i--)
    {
        k=k*10000+a[t].num[i];
        a[t].num[i]=k/m;
        k=k%m;
    }
    while(!a[t].num[a[t].g-1]) a[t].g--;
}

long long int qumo()   //取模
{
    long long int k=0;
    for(int i=a[0].g-1;i>=0;i--)
    {
        k=k*10000+a[0].num[i];
        a[0].num[i]=k/f;
        k=k%f;
    }
    return k;
}

int main()
{
    int i,j,l;
    long long int ans;
    a[1].g=1;a[1].num[0]=1;
    for(i=2;i<=10000;i++)
    {
        cheng(i,4*i-2);
        chu(i,i+1);
    }
    while(scanf("%d",&i)>0)
    {
        a[0]=a[i];
        ans=qumo();
        printf("%lld\n",ans);
    }
    return 0;
}
