#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int e,f,c,tmp,aa,bb,ans;
	while(scanf("%d%d%d",&e,&f,&c)!=EOF)
	{
		tmp = e+f;
		ans = 0;
		while(tmp>=c)
		{
			ans += tmp/c;
			aa = tmp%c;//不够换的汽水瓶 
			bb = tmp/c;//喝掉之后新产生的汽水瓶 
			tmp = aa + bb;//这一轮汽水瓶的总和 
		}
		printf("%d\n",ans);
	}
	return 0;
}
