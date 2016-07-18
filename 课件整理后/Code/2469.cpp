/*
����Ϊ���鼯�Ļ���Ӧ��
���ڳ�Ϊ���ѵ������ˣ�Ҫ�����������ڼ��ϵ�����
���� father1 = find(a);
	 father2 = find(b);
���father1 == father2˵����һ����������ý��в���
���father1 ��= father2 ˵������һ�������Ҫ���кϲ�����
fa[father1] = father2 �˲������������Ͻ��кϲ�
�ڴ�����m�ι�ϵ������Ҫ��ѯ�ж��ٸ���ͬ�ļ��ϣ��͵ȼ��ڲ�������Ԫ���ж��ٸ���
ͬ������ 
���� 
memset(ans,0,sizeof(ans));
for(i=1;i<=n;i++)
{
	father1 = find(i);
	if(ans[father1]==0)
	{
		sum++;
		ans[father1] = 1;
	}
}
*/ 
#include <iostream>
using namespace std;
#define maxn 102
int caseT;
int fa[maxn];
int ans[maxn];
int sum;
//�������ȵĺ��� 
int find(int k)
{
	//���������Ƚ��һ�����䱾�� 
	if(fa[k] == k)
		return k;
	else
		return fa[k] = find(fa[k]); 
}
int n,m,a,b;
int main()
{
	int i,father1,father2;
	while(scanf("%d",&caseT)!=EOF)
	{
		while(caseT--)
		{
			scanf("%d%d",&n,&m);
		//��ʼ��ÿ������ʼ�ĸ��׽�����䱾�� 
			for(i=1;i<=n;i++)
				fa[i] = i;
			for(i=0;i<m;i++)
			{
				scanf("%d%d",&a,&b);
				father1 = find(a);
				father2 = find(b);
				if(father1 != father2)
				{
					fa[father1] = father2;
				}
			}
			sum = 0;
			memset(ans,0,sizeof(ans));
			for(i=1;i<=n;i++)
			{
				father1 = find(i);
				if(ans[father1]==0)
				{
					sum++;
					ans[father1] = 1;
				}
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
