/*
�����������+���仯
��dfs�Ĺ����У����ǿ��ܻ��ظ��ݹ����dfs(k1,k2);
���ʱ��������һ��������һ��dfs(k1,k2)֮���ֵ����ʼ��Ϊ0
���֮ǰû�еݹ飬��ξ͵ݹ���ȥ������dfs(k1,k2),֮���پͲ�
�õݹ���� dfs(k1,k2)��ֱ�ӻ�ȡkk[k1][k2]�ͺã��������ƽ��
�ĸ��ӶȽ���ȥ���ǱȽ�ʵ�õļ��� 
*/
#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[102];
int kk[102][102];
//��ʾ��Сֵ����val����ʣkʱ�������� 
inline int dfs(int val,int k)
{
	int tmp_ans;
	if(kk[val][k]!=0)
		return kk[val][k];
	tmp_ans = 0;
	int i;
	if(k > val)//���k>val,��ô�����k������...val k���������� 
	tmp_ans++;
	//���k����� 
	for(i=val+1;i*2<k;i++)
	{
		if(kk[i][k-i] == 0)
			kk[i][k-i] = dfs(i,k-i);//���仯���� 
		tmp_ans += kk[i][k-i];
	}
	return tmp_ans;//���ؽ�� 
}
int main()
{
	int i,ans;
	memset(a,-1,sizeof(a));
	memset(kk,0,sizeof(kk));
	while(scanf("%d",&n)&&n)
	{
		if(a[n] != -1)
			printf("%d",a[n]);
		else
		{
			ans = 0;
			for(i=1;i<=n/2;i++)
			{
				if(kk[i][n-i]==0)
					kk[i][n-i] = dfs(i,n-i);//���仯���� 
				ans += kk[i][n-i];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
