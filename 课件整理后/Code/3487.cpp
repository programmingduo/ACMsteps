/*
ͨ����Ŀ�����˽⵽����3,4,7�������ǲ���������ʾ�ġ���������Ҫͳ�Ƶ��ǳ�ȥ����3,4,7
�����֣���ǰ���������еĵڼ����� 
��Ϊ������һ���ģ�ֻ������ѯ�Ķ���һ�����������ǿ��Խ����Ԥ���������
ÿ�β�ѯ��ʱ��ֱ������������Ҳ������ν�Ĵ��
 
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
//��Ԥ�������洢s[]�����У�s[i]��ʾ��i������Ҫ������� 
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

