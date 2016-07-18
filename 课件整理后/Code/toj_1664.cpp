#include<iostream>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

const int MAX = 50002;
vector<pair<int, int> >	 mp[MAX];
queue<int> Q;
bool mark[MAX];
int s[MAX];

void SPFA(int v){
	memset(s, 0x7f, sizeof(s));
	memset(mark, 0, sizeof(mark));
	s[v] = 0;	mark[v] = 1;
	Q.push(v);
	int a,b,i;
	while(!Q.empty()){
		a = Q.front();	mark[a] = 0;	Q.pop();
		for(i = 0; i < mp[a].size(); ++i){
			b = mp[a][i].first;
			if(s[b] > s[a]+mp[a][i].second){
				s[b] = s[a]+ mp[a][i].second;
				if(!mark[b]){
					mark[b] = 1;
					Q.push(b);
				}
			}
		}
	}
}
	
int main()
{
	int i,a,b,c,n,total=0;
	scanf("%d",&n);
	for(i = 0; i < n; ++i){
		scanf("%d%d%d",&a,&b,&c);
		++b;
		total >?= b;
		mp[b].push_back(make_pair(a,-c));
	}
	for(i = 0; i <= total; ++i){
		mp[i].push_back(make_pair(i+1, 1));
		mp[i+1].push_back(make_pair(i, 0));
		mp[total+1].push_back(make_pair(i,0));
	}
	
	SPFA(total+1);
	printf("%d\n",s[total]-s[0]);
	return 0;
}

