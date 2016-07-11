#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

set<int>st[51];
set<int>::iterator it;
int stk[60], top;

bool isnum(char x){
	if (x >= '0'&&x <= '9')
		return true;
	return false;
}

int ci(char x){
	return x - '0';
}

int main(){
	int l, i, j, fa, nw, n = 50, ans[51];
	char tr[400];
	while (gets(tr)){
		l = strlen(tr);
		if (l == 0)
			continue;
		n = top = nw = fa = 0;

		for (i = 0; i < l; i++){
			if (isnum(tr[i])){
				if (i + 1 < l&&isnum(tr[i + 1])){
					nw = ci(tr[i]) * 10 + ci(tr[i + 1]);
					i++;
				}
				else
					nw = ci(tr[i]);
				stk[++top] = nw;
				++n;
			}
			else if (tr[i] == ')'){
				nw = stk[top--];
				fa = stk[top];
				if (fa){
					st[fa].insert(nw);
					st[nw].insert(fa);
				}
			}
		}

        if(n<2){
            printf("\n");
            continue;
        }
		nw = 51;
		l = 0;
		while (true){
			j = -1;
			for (i = 1; i <= n; i++){
				if (st[i].size() == 1){
					it = st[i].begin();

					fa = *it;
					j = i;
					break;
				}
			}
			if (j == -1)
				break;
			ans[l++] = fa;
			st[j].erase(fa);
			st[fa].erase(j);
		}

		printf("%d", ans[0]);
		for (i = 1; i < l; i++)
			printf(" %d", ans[i]);
		printf("\n");
		for (i = 1; i <= n; i++)
			st[i].clear();
	}
	return 0;
}
