/*
��Ŀ����ܼ򵥣�Ҫ�����n����������m��ĸ���
���ȣ�1������������ĸ���1-6����1/6����������0
�������ӵ�ʱ�����ǿ�����ô�룬
������������j��ĸ��ʵ���1������j-k�ĸ���*������k��ĸ��ʣ�1<=k<=6��
����n����������m��ĸ��ʾ���n-1����������m-k��ĸ���*������k��ĸ��ʣ�1<=k<=6�� 
������һ������f[i][j]��ʾi����������j��ĸ��ʣ���ʼ��Ϊ0
���Ը���֮ǰ�ķ������ǿ���֪��������ʽ��
 for(k=1;k<=6;k++){
		if(j>=k)//���￼�ǵ�����������k���j����ô���֮ǰ�ĵ����ǲ�����==j��
		��Ȼ����j 
		f[i][j] += f[i-1][j-k]*c[k];
		}
*/ 
#include <iostream>
using namespace std;
#define maxn 102
double f[maxn][maxn*6];
double c[7];
int t;
int main(){
	int i,j,k,m,n;
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	for(i=1;i<=6;i++)
		f[1][i] = c[i] = (double)1/6.0;
	for(i=2;i<=maxn;i++){
		for(j=2;j<=6*maxn;j++){
			for(k=1;k<=6;k++){
				if(j>=k)
				f[i][j] += f[i-1][j-k]*c[k];
				}
			}
		}
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d%d",&m,&n);
			printf("%.2lf\n",f[m][n]);
			}
		}
	return 0;
	}

