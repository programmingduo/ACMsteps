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
			aa = tmp%c;//����������ˮƿ 
			bb = tmp/c;//�ȵ�֮���²�������ˮƿ 
			tmp = aa + bb;//��һ����ˮƿ���ܺ� 
		}
		printf("%d\n",ans);
	}
	return 0;
}
