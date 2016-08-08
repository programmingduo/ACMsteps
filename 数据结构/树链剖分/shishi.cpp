#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX 200010
#define LEFT (pos << 1)
#define RIGHT (pos << 1|1)
using namespace std;

struct Edge{
	int x,y,len;
	
	Edge(int _x,int _y,int _len)
		:x(_x),y(_y),len(_len) {}
	Edge() {}	
}edge[MAX];

int points,asks,now;
int head[MAX],total;
int next[MAX],aim[MAX],length[MAX];
int src[MAX];

int son[MAX],father[MAX],deep[MAX];
int top[MAX],pos[MAX],cnt;

int tree[MAX << 2];

inline void Add(int x,int y,int len);
int PreDFS(int x,int last);
void DFS(int x,int last,int root);
void BuildTree(int l,int r,int pos);
inline int Ask(int x,int y);
int Ask(int l,int r,int x,int y,int pos);
void Modify(int l,int r,int x,int pos,int num);

int main()
{
	cin >> points >> asks >> now;
	for(int x,y,z,i = 1;i < points; ++i) {
		scanf("%d%d%d",&x,&y,&z);
		edge[i] = Edge(x,y,z);
		Add(x,y,z),Add(y,x,z);
	}
	PreDFS(1,0);
	DFS(1,0,1);
	for(int i = 1;i <= total; ++i) {
		int temp = deep[edge[i].x] > deep[edge[i].y] ? edge[i].x:edge[i].y;
		src[pos[temp]] = edge[i].len;
	}
	BuildTree(1,cnt,1);
	for(int flag,x,y,i = 1;i <= asks; ++i) {
		scanf("%d%d",&flag,&x);
		if(!flag) {
			printf("%d\n",Ask(now,x));
			now = x;
		}
		else {
			scanf("%d",&y);
			int temp = deep[edge[x].x] > deep[edge[x].y] ? edge[x].x:edge[x].y;
			Modify(1,cnt,pos[temp],1,y);
		}
	}
	return 0;
}

inline void Add(int x,int y,int len)
{
	next[++total] = head[x];
	aim[total] = y;
	length[total] = len;
	head[x] = total;
}

int PreDFS(int x,int last)
{
	deep[x] = deep[last] + 1;
	father[x] = last;
	int re = 1,_max = 0;
	for(int i = head[x];i;i = next[i]) {
		if(aim[i] == last)	continue;
		int temp = PreDFS(aim[i],x);
		if(temp > _max)	temp = _max,son[x] = aim[i];
		re += temp;
	}
	return re;
}

void DFS(int x,int last,int root)
{
	pos[x] = ++cnt;
	top[x] = root;
	if(son[x])	DFS(son[x],x,root);
	for(int i = head[x];i;i = next[i]) {
		if(aim[i] == last || aim[i] == son[x])	continue;
		DFS(aim[i],x,aim[i]);
	}
}

void BuildTree(int l,int r,int pos)
{
	if(l == r) {
		tree[pos] = src[l];
		return ;
	}
	int mid = (l + r) >> 1;
	BuildTree(l,mid,LEFT);
	BuildTree(mid + 1,r,RIGHT);
	tree[pos] = tree[LEFT] + tree[RIGHT];
}

inline int Ask(int x,int y)
{
	int re = 0;
	while(top[x] != top[y]) {
		if(deep[top[x]] < deep[top[y]])
			swap(x,y);
		re += Ask(1,cnt,pos[top[x]],pos[x],1);
		x= father[top[x]];
	}
	if(x == y)	return re;
	if(deep[x] < deep[y])
		swap(x,y);
	re += Ask(1,cnt,pos[y] + 1,pos[x],1);
	return re;
}

int Ask(int l,int r,int x,int y,int pos)
{
	if(l == x && r == y)	return tree[pos];
	int mid = (l + r) >> 1;
	if(y <= mid)	return Ask(l,mid,x,y,LEFT);
	if(x > mid)		return Ask(mid + 1,r,x,y,RIGHT);
	int left = Ask(l,mid,x,mid,LEFT);
	int right = Ask(mid + 1,r,mid + 1,y,RIGHT);
	return left + right;
}

void Modify(int l,int r,int x,int pos,int num)
{
	if(l == r) {
		tree[pos] = num;
		return ;
	}
	int mid = (l + r) >> 1;
	if(x <= mid)	Modify(l,mid,x,LEFT,num);
	else	Modify(mid + 1,r,x,RIGHT,num);
	tree[pos] = tree[LEFT] + tree[RIGHT];
}
