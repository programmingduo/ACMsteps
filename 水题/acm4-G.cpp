#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;


int main(){
	int image[100][100];
	int y,x;
	int ans;
	char s[101];

	scanf("%d%d",&y,&x);
	for(int i=0;i<y;i++){
		scanf("%s",s);
		for(int j=0;j<x;j++){
			if(s[j]=='W')
				image[i][j]=1;
			else
				image[i][j]=-1;
		}
	}
	ans=0;
	for(int i=y-1;i>=0;i--){
		for(int j=x-1;j>=0;j--){
			if(image[i][j]!=0){
				ans++;
				for(int k=0;k<=i;k++)
					for(int w=0;w<=j;w++)
						image[k][w]-=image[i][j];
			}
		}
	}

	printf("%d",ans);

}
