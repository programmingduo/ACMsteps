/*
ͨ����Ŀ��֪������ֻҪ�ҵ�������Ӧ��m��b�ͺ�
�п��ǵ�
1 2
2 3
�����Ķ�Ӧ��
1 2
3 2
��һ��Ч��
ֻ�������� 
1 3
3 2
��
1 3
2 3 
Ч���ǲ�һ����
�۲����֪������Ľ�����Ƿ���Ҫ��� 
�������ǿ��Խ�������������
֮���Ӧ����ͺ� 
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
