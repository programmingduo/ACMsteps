#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 50010;
vector<int> mp[MAXN];
map<string,int> name2id;
int tot, ans[MAXN];
int q[MAXN], tk[MAXN];

int find_add(char *buf) {
	if (name2id.find((string)buf) == name2id.end()) {
		name2id[(string)buf] = tot++;	
		return tot - 1;
	} else return name2id[(string)buf];
}

void bfs(int k) {
	int head, tail, i, j;
	head = 0; tail = 1;
	q[0] = k; tk[k] = 1; ans[k] = 0;
	while (head < tail) {
		for (i = 0 ; i < mp[q[head]].size() ; i++) {
			j = mp[q[head]][i];
			if (tk[j] == 0) {
				tk[j] = 1;
				q[tail++] = j;
				ans[j] = ans[q[head]] + 1;
			}
		}
		++head;
	}	
}

int main()
{
	char buf1[30], buf2[30];
	int n, m, t1, t2, tmp;
	scanf("%d",&n);
	tot = 0;
	while (n--) {
		scanf("%s%s",buf1,buf2);
		t1 = find_add(buf1);
		t2 = find_add(buf2);
		mp[t1].push_back(t2);
		mp[t2].push_back(t1);
	}
	memset(ans, -1, sizeof(ans));
	if (name2id.find("Erdos") == name2id.end()) {
		scanf("%d",&m);
		while (m--) {
			scanf("%s",buf1);
			if (strcmp(buf1, "Erdos") == 0) printf("0\n");
			else printf("infinity\n");
		}
		return 0;
	}
	bfs(name2id["Erdos"]);
	scanf("%d",&m);
	while (m--) {
		scanf("%s",buf1);
		if (name2id.find((string)buf1) == name2id.end()) {
			printf("infinity\n");
			continue;
		}
		tmp = ans[name2id[(string)buf1]];
		if (tmp != -1) printf("%d\n",tmp);
		else printf("infinity\n");
	}
	//system("pause");
	return 0;
}