/*
�����Ŀ���ݼ�������Ŀ
��Ϊ[-2^64+1,2^64-1].�����Χ֮���ǳ�����long long int���͵�
����Ҫô��biginteger(Java),Ҫô�߾���ģ��
�Ƚ����������double�������е����ִ���double���ͱ������ҳ����ֵ����Сֵ
printf("%.0lf\n",mx-mn);�����ǲ����С�������Ĳ��� 
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
