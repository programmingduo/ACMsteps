/*
通过题目我们了解到包含3,4,7的数字是不能正常显示的。所以我们要统计的是除去包含3,4,7
的数字，当前数是数列中的第几个。 
因为规则都是一样的，只不过查询的对象不一样，所以我们可以将结果预处理出来，
每次查询的时候直接输出结果。这也就是所谓的打表
 
*/

#include <iostream>
using namespace std;
#define maxn 1000000
int s[maxn+10];
int nn[15];
int main(){
	int i = 1;
	int tmp,ff,k;
	int tp = 1;
//将预处理结果存储s[]数组中，s[i]表示第i个符合要求的数字 
	while(tp<=maxn)
	{
		tmp = i;
		ff = 0;
		while(tmp!=0)
		{
			k = tmp%10;
			if(k==3||k==4||k==7)
			{
				ff = 1;
				break;
			}
		    tmp = tmp/10;
		}
		if(ff==0)
		{
			s[tp] = i;
			tp++;
		}
		i++;
	}
	int n,kk,ktp;
	while(scanf("%d",&n)!=EOF)
	{
		kk = s[n];
		ktp = 0;
		while(kk!=0)
		{
			nn[ktp] = kk%10;
			kk/=10;
			ktp++;
		}
		for(i=0;i<ktp;i++)
		{
			if(nn[i]==6)
				printf("9");
			else if(nn[i]==9)
				printf("6");
			else
				printf("%d",nn[i]);
		}
		printf("\n");
	}
	return 0;
}

