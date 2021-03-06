#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/* 给N个模式串，每个不超过10个字符，再给M个句子，句子长度< 100 判断每个句子里是否包含模式串
  N < 10, M < 10 ,字符都是小写字母
*/

#define	LETTERS 26
int nNodesCount = 0;

struct CNode 
{
	CNode * pChilds[LETTERS];
	CNode * pPrev;
	bool bStopNode;
	void Init() {
		memset(pChilds,0,sizeof(pChilds));
		bStopNode = false;
		pPrev = NULL;
	}
};

CNode Tree[200] ;//10个模式串，每个10个字符，每个字符一个节点，也只要100个节点
void Insert( CNode * pRoot, char * s)
{
	for( int i = 0; s[i]; i ++ ) {
		if( pRoot->pChilds[s[i]-'a'] == NULL) {
			pRoot->pChilds[s[i]-'a'] = Tree + nNodesCount;
			nNodesCount ++;
		}
		pRoot = pRoot->pChilds[s[i]-'a'];
	}
	pRoot->bStopNode = true;
}
void BuildDfa( )
{
	for( int i = 0;i < LETTERS ;i ++ )
		Tree[0].pChilds[i] = Tree + 1;
	Tree[0].pPrev = NULL;
	Tree[1].pPrev = Tree;
	deque<CNode * > q;
	q.push_back(Tree+1);
	while( ! q.empty() ){
		CNode * pRoot = q.front();
		q.pop_front();
		for( int i = 0; i < LETTERS ; i ++ ) {
			CNode * p = pRoot->pChilds[i];
			if( p) {
				CNode * pPrev = pRoot->pPrev;
				while( pPrev ) {
					if( pPrev->pChilds[i] ) {
						p->pPrev = pPrev->pChilds[i];
						if( p->pPrev->bStopNode ) 
							p->bStopNode = true; //自己的pPrev指向的节点是危险节点，则自己也是危险节点
						break;
					}
					else
						pPrev = pPrev->pPrev;

				}
				q.push_back(p);
			}
		}
	}
}
bool SearchDfa(char * s)
{
	CNode * p = Tree + 1;
	for( int i = 0; s[i] ;i ++ ) {
		while(true) { 
			if( p->pChilds[s[i]-'a']) {
				p = p->pChilds[s[i]-'a'];
				if( p->bStopNode )
					return true;
				break;
			}
			else 
				p = p->pPrev;
		}
	}
	return false;
}
int main()
{
	
	nNodesCount = 2;
	int M,N;
//	freopen("d:\\tmp\\dfa.txt","r",stdin);
	
	scanf("%d%d",&N,&M);  	//N个模式串，M个句子
	for( int i = 0;i < N; i ++ )  {
		char s[20];
		scanf("%s",s);
		Insert(Tree + 1,s);
	}
	BuildDfa();
	for( int i = 0 ;i < M;i ++ ) {
		char s[200];
		scanf("%s",s);
		cout << SearchDfa(s) << endl;
	}
	return 0;
}