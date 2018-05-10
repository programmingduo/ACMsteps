/*
通过题目可知，我们只要找到尽量对应的m和b就好
有考虑到
1 2
2 3
这样的对应和
1 2
3 2
是一个效果
只有在类似 
1 3
3 2
和
1 3
2 3 
效果是不一样的
观察可以知道排序的结果总是符合要求的 
所以我们可以将两个数组排序
之后对应计算就好 
*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[25002];
int b[25002];
int main()
{
	int n,c1,c2,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum = 0;
		scanf("%d%d",&c1,&c2);
		for(int i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++)
		{
			if(a[i]<b[i])
			sum+=c1*(b[i]-a[i]);
			else
			sum+=c2*(a[i]-b[i]);
		}
		printf("%d\n",sum);
	}
	return 0;
}
