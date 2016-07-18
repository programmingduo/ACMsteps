/*
这题主要是对排序技巧的训练 
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100
int dd[N][N];
int stack[N];
int aa[N];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&dd[i][j]);
				aa[j] = dd[i][j];
				}
			sort(aa,aa+n);
			stack[i] = aa[n/2];
			}
		sort(stack,stack+n);
		printf("%d\n",stack[n/2]);
		}
	return 0;
	}

