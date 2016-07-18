#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100004
int a[maxn];
int n,caseT;
int tp;
bool cmp(const int &a,const int &b)
{
	return a > b;
}
int main()
{
	int i,tmp,tmp1,tmp2,ans;
	while(scanf("%d",&caseT)!=EOF)
	{
		while(caseT--)
		{
			tp = 0;
			ans = 0;
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d",&tmp);
				a[tp++] = tmp;
				push_heap(a,a+tp,cmp);
			}
			for(i=0;i<n-1;i++)
			{
				pop_heap(a,a+tp,cmp);
				tmp1 = a[tp-1];
				tp--;
				pop_heap(a,a+tp,cmp);
				tmp2 = a[tp-1];
				tp--;
				ans += tmp1 + tmp2;
				a[tp++] = tmp1+tmp2;
				push_heap(a,a+tp,cmp);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
