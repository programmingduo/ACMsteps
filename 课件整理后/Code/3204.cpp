/*
largest depth number only if it is verified by the fact that the same depth 
appears in an adjacent reading. 
������仰����֪�� largest depth number���һ��Ҫ���ڰ˸������ϴ�����֮��ȵĵ�
���Խ���˼·���Ƕ���ÿ���㣬������˸��������Ƿ������֮��ͬ�ĵ㣬���ڵĻ�������
��ѡ�𰸣�����ֻ��ӱ�ѡ����ѡȡ���ľͺ�
�����Ŀֵ��ע����� 
int d[8][2] = {-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
��������Ӧ��
��������ڿ��ǰ˸������ʱ��Ƚϼ�㣬Ҳ��һ�ּ���
d[0][0] = -1 d[0][1] = 0;
d[1][0] = -1 d[1][1] = 1;
d[2][0] = 0  d[2][1] = 1;
d[3][0] = 1  d[3][1] = 1;
d[4][0] = 1  d[4][1] = 0;
d[5][0] = 1  d[5][1] = -1;
d[6][0] = 0  d[6][1] = -1;
d[7][0] = -1 d[7][1] = -1;
�ֱ������˸���������չ�������뵱ǰ������������ƫ���� 
*/ 
#include <iostream>
#include <algorithm>
using namespace std;
int map[55][55];
int a,b;
int d[8][2] = {-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
struct V
{
	int x,y,dep;
}v[2600];
int top,ans;
bool cmp(V m,V n)
{
	return m.dep>n.dep;
}
bool check(V t)
{
	int m,n;
	for(int i=0;i<8;i++)
	{
		m = t.x + d[i][0];
		n = t.y + d[i][1];
		if(m>0&&m<=a&&n>0&&n<=b&&map[m][n]==t.dep)
		return true;
	}
	return false;
}
int main()
{
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		top = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				scanf("%d",&map[i][j]);
				v[top].x = i;
				v[top].y = j;
				v[top].dep = map[i][j];
				top++;
			}
		}
		sort(v,v+top,cmp);
		for(int i=0;i<top;i++)
		{
			if(check(v[i])==true)
			{	
				ans = v[i].dep;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
