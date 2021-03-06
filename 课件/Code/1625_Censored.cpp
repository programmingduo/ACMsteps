#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 60
#define	LETTERS 256
int nNodesCount = 0;
/* 特殊数据：
4 3 2
abcd
dbd
b
*/
struct HugeInt
{
	int val[110];
	HugeInt() {
		memset(val,0,sizeof(val));
	}
	void operator += ( const HugeInt & a) {
		for( int i = 0; i < 100; i ++ ) {
			val[i] += a.val [i];
			if( val[i] >= 10 ) {
				val[i] -= 10;
				val[i+1] ++;
			}
		}
	}
};
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
HugeInt Ans[60][200];//Ans[i][j]表示长度为i的字符串终止于trie图上非危险节点(即不包含模式串）的情况总数
//int Ans[8][8];
void Insert( CNode * pRoot, unsigned char * s)
// 用char会RE
{
	for( int i = 0; s[i]; i ++ ) {
		if( pRoot->pChilds[s[i]] == NULL) {
			pRoot->pChilds[s[i]] = Tree + nNodesCount;
			nNodesCount ++;
		}
		pRoot = pRoot->pChilds[s[i]];
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
		do { 
			if( p->pChilds[s[i]]) {
				p = p->pChilds[s[i]];
				if( p->bStopNode )
					return true;
				break;
			}
			else 
				p = p->pPrev;
		}while(p != Tree + 1);		
	}
	return false;
}
int main()
{

	nNodesCount = 2;
	int M,N,P;
	//freopen("d:\\tmp\\23.in","r",stdin);
	scanf("%d%d%d",&N,&M,&P);  	//M 个字符,句子长度N,  P 个模式串

	unsigned char alph[MAX_N]; // 用char会RE
	scanf("%s",alph);
	for( int i = 0;i < P; i ++ )  {
		unsigned char s[20];
		scanf("%s",s);
		Insert(Tree + 1,s);
	}
	BuildDfa();
	memset(Ans,0,sizeof(Ans));
	Ans[0][1].val[0] = 1;
	//Ans[0][1] = 1;
	for( int i = 0; i < M; i ++) {
		for( int s = 1	; s < nNodesCount ; s ++) {
			if( Tree[s].bStopNode )
				continue;
			for( int k = 0; alph[k] ;k ++) {
				CNode * p = Tree + s;
				while( true) {
					CNode * q = p->pChilds[alph[k]];
					if( q ) {
						if( q->bStopNode == false) {
							Ans[i+1][q-Tree] += Ans[i][s];
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
	HugeInt Sum;
	//int Sum = 0;
	for( int i = 1 ; i < nNodesCount ; i ++ ) {
		if( Tree[i].bStopNode == false )
			Sum += Ans[M][i];
	}
	//printf("%d\n",Sum);
	
	bool bValid = false;
	for( int i = 99; i >= 0; i -- )  {
		if( Sum.val[i] ) 
			bValid = true;
		if( Sum.val[i] || bValid )
			printf("%d",Sum.val[i]);
	}
	if( !bValid )
		printf("0");
	printf("\n");
	
	/*
	Insert(Tree + 1, "abcde");
	Insert(Tree + 1, "defg");
	Insert(Tree + 1, "cdke");
	Insert(Tree + 1, "ab");
	Insert(Tree + 1, "f");
	BuildDfa();
	cout << SearchDfa( "abcdkef") <<endl;
	cout << SearchDfa( "abkef") <<endl;
	cout << SearchDfa( "bcd") <<endl;
	cout << SearchDfa( "bca") <<endl;
	cout << SearchDfa( "add") <<endl;
	cout << SearchDfa( "ab") <<endl;
	cout << SearchDfa( "qab") <<endl;
	cout << SearchDfa( "g") <<endl;
	*/
	return 0;
}