/*
����ÿ�β�ѯ����Ҫ֪��������������
������������� (tt<=s[mid].v&&tt>=s[mid].u)
ttΪ��ѯĿ��
˳����ҿ��ԣ�����ʱ���ϲ�����
���￴���������Ҷ˵��໥�������ǵ�����
��˿������ö��ֲ���
�� tt > s[mid].v ˵����ѯ�϶����ҵ�ǰ����������ұ�
�������ǲ��ٲ�����ߵ����䣬ȥ�����ұߵļ��� �����������Ϊst = mid + 1
�� tt < s[mid].u ˵����ѯ�϶����ҵ�ǰ������������
ͬ������������Ϊ ed = mid - 1
�� tt<=s[mid].v&&tt>=s[mid].u ˵����ѯ�ڿ��ǵ������ڲ�
������ 
*/
#include <iostream>
#include <cstring>
using namespace std;
#define maxn  50003
int n,q;
struct SS
{
	int u,v;
}s[maxn];
int main()
{
	int tmp,i,tt,ans;
	int st,ed,mid;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		tmp = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&tt);
			s[i].u = tmp;
			s[i].v = tmp + tt - 1;
			tmp = s[i].v + 1;
		}
		while(q--)
		{
			scanf("%d",&tt);
			st = 0; ed = n;
			while(st <= ed)
			{
				mid = (st + ed)>>1;
				if(tt<=s[mid].v&&tt>=s[mid].u)
				{
					ans = mid + 1;
					break;
				}
				else if(tt > s[mid].v)
				{
					st = mid + 1;
				}
				else
					ed = mid - 1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
