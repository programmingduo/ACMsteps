#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

const int MAX1 = 50000, MAX2 = 5002;
map <string, int> mp;
vector<pair<int,int> > edge[10];

int p[MAX2],rank[MAX2], mark[MAX2];

void MakeSet(int n){
	for(int i = 0; i <= n; i++){
		rank[i] = 0;
		p[i] = i;
	}
}
int Find(int v){
	if(v == p[v])return v;
	return p[v] = Find(p[v]);
}
void Union(int x, int y){
	x = Find(x);	y = Find(y);
	if(rank[x] < rank[y])
		p[x] = y;
	else if(rank[x] > rank[y])
		p[y] = x;
	else if(x != y){
		p[y] = x;
		rank[x]++;
	}
}
int Kruskal(int n){
	int ans = 0;
	MakeSet(n);
	int i,j,u,v;
	for(i = 1; i < 10; i++){
		for(j = 0; j < edge[i].size(); j++){
			u = edge[i][j].first;	v = edge[i][j].second;
			if(Find(u) == Find(v))continue;
			ans += i;
			Union(u, v);
		}
	}
	return ans;
}

int main()
{
	int n,m,i,j,ans,t,t1,t2,d;
	char str1[100], str2[100];
	scanf("%d%d", &m,&n);
		for(i = 0; i < 10; i++)
			edge[i].clear();
		mp.clear();
		t = 1;
		map <string, int> :: iterator pos;
		for(j = 0; j < n; j++){
			scanf("%s%s%d", str1, str2, &d);
			pos = mp.find(string(str1));
			if(pos == mp.end()){
				t1 = t++;
				mp[string(str1)] = t1;
			}
			else t1 = (*pos).second;
			pos = mp.find(string(str2));
			if(pos == mp.end()){
				t2 = t++;
				mp[string(str2)] = t2;
			}
			else t2 = (*pos).second;
			edge[d].push_back(make_pair(t1,t2));
		}
		ans = Kruskal(m);
		memset(mark, 0, sizeof(mark));
		for(i = 1; i <= m; i++)
			mark[Find(i)] = 10;
		for(i = 1; i <= m; i++)
			ans += mark[i];
		int yuan = ans/10, jiao = ans%10;
		printf("The total cost is %d Yuan %d Jiao.\n", yuan, jiao);
	return 0;
}
