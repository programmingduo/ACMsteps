//对于已经分解的整数A=(p1^k1)*(p2^k2)*(p3^k3)*....*(pn^kn)
//有A的所有因子之和为
//S = (1+p1+p1^2+p1^3+...p1^k1) * (1+p2+p2^2+p2^3+….p2^k2) * (1+p3+ p3^3+…+ p3^k3) * .... * (1+pn+pn^2+pn^3+...pn^kn)
//

//用递归二分求等比数列1+pi+pi^2+pi^3+...+pi^n：
//（1）若n为奇数,一共有偶数项，则：
//      1 + p + p^2 + p^3 +...+ p^n
//      = (1+p^(n/2+1)) + p * (1+p^(n/2+1)) +...+ p^(n/2) * (1+p^(n/2+1))
//      = (1 + p + p^2 +...+ p^(n/2)) * (1 + p^(n/2+1))
//上式红色加粗的前半部分恰好就是原式的一半，那么只需要不断递归二分求和就可以了，后半部分为幂次式，将在下面第4点讲述计算方法。
//
//（2）若n为偶数,一共有奇数项,则:
//      1 + p + p^2 + p^3 +...+ p^n
//      = (1+p^(n/2+1)) + p * (1+p^(n/2+1)) +...+ p^(n/2-1) * (1+p^(n/2+1)) + p^(n/2)
//      = (1 + p + p^2 +...+ p^(n/2-1)) * (1+p^(n/2+1)) + p^(n/2);
//   上式红色加粗的前半部分恰好就是原式的一半，依然递归求解

/*
POJ 1845 Sumdiv
求A^B的所有约数之和%9901

*/
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

#define MOD 9901

//******************************************
//素数筛选和合数分解
const int MAXN=10000;
int prime[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
long long factor[100][2];
int fatCnt;
int getFactors(long long x)
{
    fatCnt=0;
    long long tmp=x;
    for(int i=1;prime[i]<=tmp/prime[i];i++)
    {
        factor[fatCnt][1]=0;
        if(tmp%prime[i]==0)
        {
            factor[fatCnt][0]=prime[i];
            while(tmp%prime[i]==0)
            {
                factor[fatCnt][1]++;
                tmp/=prime[i];
            }
            fatCnt++;
        }
    }
    if(tmp!=1)
    {
        factor[fatCnt][0]=tmp;
        factor[fatCnt++][1]=1;
    }
    return fatCnt;
}

//******************************************
long long pow_m(long long a,long long n)//快速模幂运算
{
    long long res=1;
    long long tmp=a%MOD;
    while(n)
    {
        if(n&1){res*=tmp;res%=MOD;}
        n>>=1;
        tmp*=tmp;
        tmp%=MOD;
    }
    return res;
}
long long sum(long long p,long long n)//计算1+p+p^2+````+p^n
{
    if(p==0)return 0;
    if(n==0)return 1;
    if(n&1)//奇数
    {
        return ((1+pow_m(p,n/2+1))%MOD*sum(p,n/2)%MOD)%MOD;
    }
    else return ((1+pow_m(p,n/2+1))%MOD*sum(p,n/2-1)+pow_m(p,n/2)%MOD)%MOD;

}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int A,B;
    getPrime();
    while(scanf("%d%d",&A,&B)!=EOF)
    {
        getFactors(A);
        long long ans=1;
        for(int i=0;i<fatCnt;i++)
        {
            ans*=(sum(factor[i][0],B*factor[i][1])%MOD);
            ans%=MOD;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
