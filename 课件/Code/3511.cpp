/*
深度优先搜索+记忆化
在dfs的过程中，我们可能会重复递归求解dfs(k1,k2);
这个时候我们用一个数组标记一下dfs(k1,k2)之后的值，初始化为0
如果之前没有递归，这次就递归下去，计算dfs(k1,k2),之后再就不
用递归计算 dfs(k1,k2)，直接获取kk[k1][k2]就好，这样会把平均
的复杂度降下去，是比较实用的技巧 
*/
#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[102];
int kk[102][102];
//表示最小值大于val，还剩k时的序列数 
inline int dfs(int val,int k)
{
	int tmp_ans;
	if(kk[val][k]!=0)
		return kk[val][k];
	tmp_ans = 0;
	int i;
	if(k > val)//如果k>val,那么不拆分k，构成...val k这样的序列 
	tmp_ans++;
	//拆分k的情况 
	for(i=val+1;i*2<k;i++)
	{
		if(kk[i][k-i] == 0)
			kk[i][k-i] = dfs(i,k-i);//记忆化部分 
		tmp_ans += kk[i][k-i];
	}
	return tmp_ans;//返回结果 
}
int main()
{
	int i,ans;
	memset(a,-1,sizeof(a));
	memset(kk,0,sizeof(kk));
	while(scanf("%d",&n)&&n)
	{
		if(a[n] != -1)
			printf("%d",a[n]);
		else
		{
			ans = 0;
			for(i=1;i<=n/2;i++)
			{
				if(kk[i][n-i]==0)
					kk[i][n-i] = dfs(i,n-i);//记忆化部分 
				ans += kk[i][n-i];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
