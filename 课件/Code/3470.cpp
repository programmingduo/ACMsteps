/*
题目描述类似于二分查找
联想2进制，仔细分析
1->1
2->2
3->2
4->3
..
..
8->4
所以知道在2^n--2^(n+1)之间(不包括2^(n+1))的结果是n
所以顺序枚举就好 
ps：1<<ans 熟悉位运算 2^ans  
*/
#include <iostream>
using namespace std;
int t,n;
int main()
{
	int ans;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			ans = 0;
			scanf("%d",&n);
			while(1)
			{
				if(n<(1<<ans))
					break;
				else
					ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
