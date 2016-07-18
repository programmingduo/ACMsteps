/*
题目大意很简单，要求求出n个骰子掷出m点的概率
首先，1个骰子掷出点的概率1-6都是1/6，其他都是0
两个骰子的时候我们可以这么想，
两个骰子掷出j点的概率等于1个掷出j-k的概率*再掷出k点的概率（1<=k<=6）
所以n个骰子掷出m点的概率就是n-1个骰子掷出m-k点的概率*在掷出k点的概率（1<=k<=6） 
我们用一个数组f[i][j]表示i个骰子掷出j点的概率，初始化为0
所以根据之前的分析我们可以知道这样的式子
 for(k=1;k<=6;k++){
		if(j>=k)//这里考虑到若新掷出的k点比j大，那么结合之前的点数是不可能==j的
		必然大于j 
		f[i][j] += f[i-1][j-k]*c[k];
		}
*/ 
#include <iostream>
using namespace std;
#define maxn 102
double f[maxn][maxn*6];
double c[7];
int t;
int main(){
	int i,j,k,m,n;
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	for(i=1;i<=6;i++)
		f[1][i] = c[i] = (double)1/6.0;
	for(i=2;i<=maxn;i++){
		for(j=2;j<=6*maxn;j++){
			for(k=1;k<=6;k++){
				if(j>=k)
				f[i][j] += f[i-1][j-k]*c[k];
				}
			}
		}
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d%d",&m,&n);
			printf("%.2lf\n",f[m][n]);
			}
		}
	return 0;
	}

