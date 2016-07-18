#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 10002
int n;
int a[maxn];
bool cmp(const int &a, const int &b)
{
	return  a > b;
} 
int main()
{
	int i,tmp,ans;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(i == 0)
				tmp = a[i];
		}
		//从大到小排序 
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
		{
			if(tmp == a[i])
			{//找到第一个相等的 
				ans = i;
				break;
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
