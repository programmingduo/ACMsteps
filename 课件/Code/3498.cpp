/*
这个题目数据技巧性题目
因为[-2^64+1,2^64-1].这个范围之差是超过了long long int类型的
所以要么用biginteger(Java),要么高精度模拟
比较巧妙的是用double，将所有的数字存入double类型变量，找出最大值和最小值
printf("%.0lf\n",mx-mn);这样是不输出小数点后面的操作 
*/
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	double mx,mn;
	double aa;
	int t,n;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d",&n);
			mx = -(1e100);
			mn = 1e100;
			while(n--)
			{
				scanf("%lf",&aa);
				if(aa > mx)
				    mx = aa;
				if(aa < mn)
				    mn = aa;
			}
			printf("%.0lf\n",mx-mn);
		}
	}
	return 0;
}
