#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 60
#define	LETTERS 4
int nNodesCount = 0;
int Idx[LETTERS ]; //字符和儿子边标号的对照表 
#define MY_MAX 2000
struct CNode 
{
	CNode * pChilds[LETTERS];
	CNode * pPrev;
	bool bStopNode; //为true表示终止节点或不安全节点

	void Init() {
		memset(pChilds,0,sizeof(pChilds));
		bStopNode = false;
		pPrev = NULL;
	}
};

#define MAX_NODES 2000
CNode Tree[MAX_NODES] ;//50个模式串，每个20个字符，每个字符一个节点，也只要1000个节点
int Ans[1200][2000]; //Ans[i][j]表示长度为i的字符串终止于trie图上非危险节点j时至少要修改多少字符
void Insert( CNode * pRoot, char * s)
{
	for( int i = 0; s[i]; i ++ ) {

		if( pRoot->pChilds[Idx[s[i]]] == NULL) {
			pRoot->pChilds[Idx[s[i]]] = Tree + nNodesCount;
			nNodesCount ++;
		}
		pRoot = pRoot->pChilds[Idx[s[i]]];
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
int main()
{

	int M,N,P;
	//freopen("d:\\tmp\\3691.txt","r",stdin);

	Idx['A'] = 0;
	Idx['C'] = 1;
	Idx['G'] = 2;
	Idx['T'] = 3;
	int nCaseNo = 0;
	while(true) {
		scanf("%d",&N);
		if( N == 0)
			break;
		char s[30];
		nNodesCount = 2;
		for( int i = 0; i < MAX_NODES ; i ++)
			Tree[i].Init();
		for( int i = 0; i < N;i ++ ) {
			scanf("%s",s);
			Insert(Tree + 1,s);
		}
		char szOri[2000];
		scanf("%s",szOri);
		M = strlen( szOri);
		BuildDfa();

		for( int i = 0; i < 1200; i ++ )
			for( int j = 0; j < 2000; j ++ )
				Ans[i][j] =MY_MAX;

		Ans[0][1] = 0;
		for( int i = 0; i < M; i ++) {
			for( int s = 1	; s < nNodesCount ; s ++) {
				if( Tree[s].bStopNode )
					continue;
				for( int k = 0; k < LETTERS ;k ++) {
					CNode * p = Tree + s;
					while( true) {
						CNode * q = p->pChilds[k];
						if( q ) {
							if( q->bStopNode == false) {
								if( Idx[szOri[i]] != k ) // 用上下标为i的字符，则长度已经是i+1
									Ans[i+1][q-Tree] = min(Ans[i+1][q-Tree], Ans[i][s] + 1);
								else
									Ans[i+1][q-Tree] = min(Ans[i+1][q-Tree],Ans[i][s]);
							}
							break;
						}
						else {
							p = p->pPrev;
							if( p->bStopNode )
								break;
						}
					}
				}
			}
		}
		int nMin = MY_MAX;
		for( int i = 1 ; i < nNodesCount ; i ++ ) {
			if( Tree[i].bStopNode == false)
				nMin = min(Ans[M][i],nMin);
		}
		nCaseNo ++;
		if( nMin == MY_MAX)
			printf("Case %d: -1\n",nCaseNo);
		else	
			printf("Case %d: %d\n",nCaseNo,nMin);
	}
	return 0;
}