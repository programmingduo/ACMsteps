#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
char VirusStrings[300][1100];//����ģʽ��
int Found[1100];	// Found[i] != 0��˵����i��ģʽ���ܱ�ĸ��ƥ��
char s[6000000];	//���Զ�ȡĸ��
char s2[6000000];	//���ڽ�ѹ��ĸ��
int nTreeNodeNum;	//Trieͼ�ڵ���Ŀ
class CNode			//Trieͼ�ڵ�
{
public:
	int SuffixPtr;       //��׺ָ�룬
	int nVirusNo;   
	int Next[26];
	bool bCounted;  //���ڵ��Ƿ񡰼������ 
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
//�������� s�����ֵ���, nVirusNo�ǲ����ı�ţ���0��ʼ�� 
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
//��ѹ����ʽ�ġ�����s, չ���ɷ�ѹ����ʽ�� s2
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
//ͨ��������ȱ��������ΪTrie�����ֵ�������Ӻ�׺ָ���Թ���Trieͼ 
{
	int i;
	deque<int> q;
	q.push_back(1);//���ڵ���1�Žڵ� 
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
//s�������������򡱣���s��Trieͼ����һ�� 
{
	int root = 1;
	for( int i = 0; s[i];i ++ ) {
		int nIdx = s[i] - 'A';
		while( root >= 1 ) { //��ͼƥ���ַ�s[i] 
			if( Tree[root].Next[nIdx] != -1 ) { //s[i]��ƥ����
				root = Tree[root].Next[nIdx];//s[i]��Ӧroot�ڵ�
				int tmpPtr = root;
				while( tmpPtr >= 1 && Tree[tmpPtr].bCounted == false) {
                    Tree[tmpPtr].bCounted = true;
                    if( Tree[tmpPtr].nVirusNo != -1 )
                        Found[Tree[tmpPtr].nVirusNo] = 1;
                    tmpPtr = Tree[tmpPtr].SuffixPtr;                    
                }
				break; //��ǰ�ַ�s[i]�Ѿ���ƥ�䣬��������ȥƥ����һ���ַ�
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

