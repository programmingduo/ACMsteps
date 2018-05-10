/* UVA 105 The Skyline Problem
 * 4461339   2006-03-30 15:26:04  Accepted 0.043 Minimum robby @ TJU C++ 105 - The Skyline Problem 
 */

#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 5010;
struct BB {int l,h,r;} b[MAX];
struct SS {int pos,h,flg;} s[MAX*2];
struct ANS {int pos,h;} ans[MAX*2];
multiset <int> si;

int cmp(SS a,SS b)
{
	if (a.pos != b.pos) return a.pos < b.pos;
	else if (a.flg != b.flg) return a.flg < b.flg;
	else return a.h < b.h;
}

int cmp2(ANS a,ANS b)
{
	if (a.pos != b.pos) return a.pos < b.pos;
	return a.h > b.h;	
}

int main()
{
	int n = 0,i,ps,tmp,pans,first = 1;
	while (scanf("%d%d%d",&b[n].l,&b[n].h,&b[n].r) != EOF) ++n;
	for (i = ps = 0 ; i < n ; i++) {
		s[ps].pos = b[i].l; s[ps].h = b[i].h; s[ps++].flg = 0;
		s[ps].pos = b[i].r; s[ps].h = b[i].h; s[ps++].flg = 1;
	}
	sort(s,s+ps,cmp); 
	si.clear(); pans = 0;
	for (i = 0 ; i < ps ; i++) {
		if (s[i].flg == 0) {
			if (si.size() == 0 || s[i].h > *(--si.end())) {
				ans[pans].pos = s[i].pos;
				ans[pans++].h = s[i].h;
			}
			si.insert(s[i].h);
		} else {
			si.erase(si.find(s[i].h));
			if (si.size() == 0) {
				ans[pans].pos = s[i].pos;
				ans[pans++].h = 0;
			}
			else {
				tmp = *(--si.end());
				if (tmp < s[i].h) {
					ans[pans].pos = s[i].pos;
					ans[pans++].h = tmp;
				}
			}
		}	
	}
	sort(ans,ans+pans,cmp2);
	printf("%d %d",ans[0].pos,ans[0].h);
	for (i = 1 ; i < pans ; i++)
		if (i == 0 || ans[i].pos != ans[i-1].pos)
			printf(" %d %d",ans[i].pos,ans[i].h);
	printf("\n");
//	while (1);
	return 0;	
}

