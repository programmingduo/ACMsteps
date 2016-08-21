#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;

int iabs(int x){
	return x < 0 ? -x : x;
}

double a[maxn];
int l1,r1,l2,r2;
int t,n,m;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lf",a+i);
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			if(l1>l2){
				swap(l1,l2);
				swap(r1,r2);
			}
			if(l1==l2&&r1<r2){
				swap(r1,r2);
			}
			int lb,rb,d=r1-l1+1+r2-l2+1;
			int v = d/2;
			double c1,c2;
			if(r1<l2){
				c1 = v <= r1-l1+1 ? a[l1+v-1] : a[l2+v-r1+l1-2];
				c2 = v+1 <= r1-l1+1 ? a[l1+v] : a[l2+v-r1+l1-1];
				//printf("%.1f %.1f\n",c1,c2);
			}else{
				if(v<=l2-l1){
					c1 = a[l1+v-1];
					//printf("%d\n",l1+v-1);
				}else if(v<=d-iabs(r2-r1)){
					int tmp = v-(l2-l1);
					if(tmp&1) tmp = tmp/2;
					else tmp = tmp/2-1;
					c1 = a[l2+tmp];
					//printf("%d\n",l2+tmp);
				}else{
					int tmp =d-iabs(r2-r1);
					tmp = v - tmp;
					c1 = a[min(r1,r2)+tmp];
					//printf("%d\n",min(r1,r2)+tmp);
				}
				if(v+1<=l2-l1){
					c2 = a[l1+v];
					//printf("$ %d\n",l2+v);
				}else if(v+1<=d-iabs(r2-r1)){
					int tmp = v+1-(l2-l1);
					if(tmp&1) tmp /= 2;
					else tmp = tmp/2-1;
					c2 = a[l2+tmp];
					//printf("# %d\n",l2+tmp);
				}else{
					int tmp = d-iabs(r2-r1);
					tmp = v+1-tmp;
					c2 = a[min(r1,r2)+tmp];
					//printf("! %d\n",min(r1,r2)+tmp);
				}
			}
			//printf("%.1f %.1f\n",c1,c2);
			if(d&1){
				printf("%.1f\n",c2);
			}else{
				printf("%.1f\n",(c1+c2)*0.5);
			}
		}
	}
	return 0;
}

