#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
char VirusStrings[300][1100];//病毒模式串
int Found[1100];	// Found[i] != 0则说明第i个模式串能被母串匹配
char s[6000000];	//用以读取母串
char s2[6000000];	//用于解压缩母串
int nTreeNodeNum;	//Trie图节点数目
class CNode			//Trie图节点
{
public:
	int SuffixPtr;       //后缀指针，
	int nVirusNo;   
	int Next[26];
	bool bCounted;  //本节点是否“计算过” 
	void Init() {	
		for( int i = 0; i < 26;i ++ )
			Next[i] = -1;
		SuffixPtr = -1;
		nVirusNo = -1;
		bCounted = false;
	}
};
#define MAX_NODES_NUM 300000
CNode Tree[MAX_NODES_NUM]; 
void InsertToTrieTree(char * s, int nVirusNo)
//将病毒串 s插入字典树, nVirusNo是病毒的编号，从0开始算 
{
	int root = 1;
	int nTmp;
	for( int i = 0; s[i];i ++ ) {
		int ix = s[i]-'A';
		if( Tree[root].Next[ix] == -1 ) {
			Tree[root].Next[ix] = nTreeNodeNum;
			nTreeNodeNum ++;
		}
		root = Tree[root].Next[ix];
	}
	Tree[root].nVirusNo = nVirusNo; 
}
void DecodeStr( char * s, char * s2)
//将压缩格式的“程序”s, 展开成费压缩格式的 s2
{
	int i,j,k;
	j = 0;
	i = 0;
	while( s[i] ) 	 {
		if( s[i] == '[') {
			int m = 0;
			i ++;
			while( s[i] >= '0' && s[i] <= '9' ) {
				m *= 10;
				m += s[i] - '0';
				i ++;
			}
			char r  = s[i++];
			for( int k = 0; k < m; k ++ )
			     s2[j++]= r;
			i++;     
		}
		else 
			s2[j++] = s[i++];
	}
	s2[j] = 0;
}
void BuildTrieGraph()
//通过广度优先遍历，逐层为Trie树（字典树）添加后缀指针以构成Trie图 
{
	int i;
	deque<int> q;
	q.push_back(1);//根节点是1号节点 
	while(!q.empty()) {
		int n = q.front();
		q.pop_front();
		for( i = 0;i < 26;i ++ ) {
			int v = Tree[n].Next[i];
			if( v != -1) { 
				q.push_back(v);
				int SuffixPtr = Tree[n].SuffixPtr;
				while( Tree[SuffixPtr].Next[i] == -1 )
				    SuffixPtr = Tree[SuffixPtr].SuffixPtr;
				Tree[v].SuffixPtr = Tree[SuffixPtr].Next[i];
			}
		}
	}
}
int SearchTrieGraph( char * s)
//s代表整个“程序”，将s在Trie图上走一遍 
{
	int root = 1;
	for( int i = 0; s[i];i ++ ) {
		int nIdx = s[i] - 'A';
		while( root >= 1 ) { //试图匹配字符s[i] 
			if( Tree[root].Next[nIdx] != -1 ) { //s[i]已匹配上
				root = Tree[root].Next[nIdx];//s[i]对应root节点
				int tmpPtr = root;
				while( tmpPtr >= 1 && Tree[tmpPtr].bCounted == false) {
                    Tree[tmpPtr].bCounted = true;
                    if( Tree[tmpPtr].nVirusNo != -1 )
                        Found[Tree[tmpPtr].nVirusNo] = 1;
                    tmpPtr = Tree[tmpPtr].SuffixPtr;                    
                }
				break; //当前字符s[i]已经被匹配，则跳出，去匹配下一个字符
			}
			else 
				root = Tree[root].SuffixPtr ;
		}
		if( root < 1 )
			root = 1;
	}
	return -1;
}
int main()
{
	int t;	int n;	int i,j;
	scanf("%d",&t);
	while( t--) {
		for( i = 0;i < MAX_NODES_NUM;i ++ )
			Tree[i].Init();
		for( i = 0; i < 26;i ++ )
			Tree[0].Next[i] = 1;	
		Tree[1].SuffixPtr = 0;  
		nTreeNodeNum = 2;
		memset(Found,0,sizeof(Found));
		scanf("%d",&n);
		for( i = 0;i < n;i ++ ) {
			scanf("%s", VirusStrings[i]);
			InsertToTrieTree(VirusStrings[i],i);
		}
		BuildTrieGraph();
		scanf("%s",s);
		DecodeStr(s,s2);
		SearchTrieGraph(s2);
		strrev(s2);
		SearchTrieGraph(s2);
		int nTotal = 0;
		for( i = 0;i < n;i ++)
			if( Found[i])
				nTotal ++;
		printf("%d\n",nTotal);
	}
	return 0;
}

