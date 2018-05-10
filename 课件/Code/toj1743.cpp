/* TOJ 1743 King's Treasure
 * 16 2006-05-11 18:12:08 1.5K 00:00.95 12924K C++ RoBa_Test 
 */

#include <cstdio>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 240010;
struct Q {int id,step,fa;} q[MAXN];
vector <int> a[MAXN];
int tk[MAXN],ans[MAXN];

int main()
{
	int cases,n,i,t,head,tail,src,pans;
	scanf("%d",&cases);
	while (cases--) {
		scanf("%d",&n);
		for (i = 1 ; i <= n ; i++) a[i].clear();
		for (i = 2 ; i <= n ; i++) {
			scanf("%d",&t);
			a[i].push_back(t);
			a[t].push_back(i);
		}	
		memset(tk,0,sizeof(tk));
		head = 0; tail = 1; tk[1] = 1;
		q[head].id = 1; q[head].step = 0;
		while (head < tail) {
			for (i = 0 ; i < a[q[head].id].size() ; i++)
				if (tk[a[q[head].id][i]] == 0) {
					q[tail].id = a[q[head].id][i];
					q[tail++].step = q[head].step + 1;
					tk[a[q[head].id][i]] = 1;
				}
			++head;
		}
		src = q[tail-1].id;
		memset(tk,0,sizeof(tk));
		head = 0; tail = 1; tk[src] = 1;
		q[head].id = src; q[head].step = 0; q[head].fa = -1;
		while (head < tail) {
			for (i = 0 ; i < a[q[head].id].size() ; i++)
				if (tk[a[q[head].id][i]] == 0) {
					q[tail].id = a[q[head].id][i];
					q[tail].fa = head;
					q[tail++].step = q[head].step + 1;
					tk[a[q[head].id][i]] = 1;
				}
			++head;
		}
		pans = 0; --head;
		while (head != -1) {
			ans[pans++] = q[head].id;
			head = q[head].fa;
		}	
		if (pans % 2 == 0) printf("%d %d\n",min(ans[pans/2-1],ans[pans/2]),
			max(ans[pans/2-1],ans[pans/2]));
		else printf("%d\n",ans[pans/2]);
	}
	return 0;
}
