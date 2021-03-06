//
/*二维线段树做
*/
#include <iostream>
#include <vector>
using namespace std;
#define MY_MAX 1100
int Tree[MY_MAX * 3][MY_MAX * 3];//二维线段树，每一行都是一棵完全二叉树，用于存放一棵x方向线段树，树节点只存放 起对应的区间的数字之和
int S; //矩阵宽度
void Add_x( int rooty,int rootx, int L, int R, int x ,int a)
//rooty是外维（y方向)的节点，rootx是内维(x方向)节点，rootx对应的区间是[L,R]

{
	
	Tree[rooty][rootx] += a;
	if( L == R ) 
		return;
	int mid = (L + R )/2;
	if( x <= mid )
		Add_x(rooty,( rootx << 1) + 1, L ,mid, x, a);
	else
		Add_x(rooty,( rootx << 1) + 2, mid + 1,R, x, a);

}

void Add_y(int rooty, int L,int R, int y, int x,int a)
//rooty 是外维(y方向）节点，其对应的区间是[L,R]
{
	Add_x( rooty,0, 1, S, x,a);
	if( L == R)
		return;
	int mid = (L + R )/2;
	if( y <= mid ) 
		Add_y( ( rooty << 1) + 1, L, mid,y, x, a);
	else
		Add_y( ( rooty << 1) + 2, mid+1, R, y, x, a);
}
int QuerySum_x(int rooty, int rootx, int L, int R ,int x1,int x2)
{
	if( L == x1 && R == x2)
		return Tree[rooty][rootx];
	int mid = ( L + R ) /2 ;
	if( x2 <= mid ) 
		return QuerySum_x( rooty, (rootx << 1) + 1, L, mid,x1,x2);
	else if( x1 > mid )
		return QuerySum_x( rooty, (rootx << 1) + 2, mid+1,R, x1,x2);
	else
		return QuerySum_x( rooty,(rootx << 1) + 1, L, mid ,x1,mid) +
			   QuerySum_x( rooty,(rootx << 1) + 2, mid + 1, R, mid + 1,x2);

}

int QuerySum_y(int rooty, int L, int R ,int y1, int y2, int x1,int x2)
{
	if( L == y1 && R == y2 )
		return QuerySum_x(rooty,0,1,S,x1,x2);
	int mid = ( L + R ) /2;
	if( y2 <= mid ) 
		return QuerySum_y( (rooty << 1) + 1, L, mid ,y1,y2,x1,x2);
	if( y1 > mid )
		return QuerySum_y( (rooty << 1) + 2, mid + 1,R, y1,y2,x1,x2);
	else
		return QuerySum_y( (rooty << 1) + 1, L, mid ,y1,mid ,x1,x2) +
			   QuerySum_y( (rooty << 1) + 2, mid + 1, R, mid + 1,y2 ,x1,x2);
}

int main()
{
	int cmd;	
	int x,y,a,l,b,r,t;	
//	freopen("d:\\tmp\\1195.txt","r",stdin);
	int Sum = 0;
	while( true) {
		scanf("%d",&cmd);
		switch( cmd) {
			case 0:
				scanf("%d",& S);
				memset( Tree,0,sizeof(Tree));
				break;
			case 1:
				scanf("%d%d%d",&x ,&y,&a);
				Add_y(0, 1,S, y + 1, x + 1, a);
				break;
			case 2:
				scanf("%d%d%d%d",&l , &b, &r,&t);
				l ++; b++; r ++; t ++;
				printf("%d\n",QuerySum_y(0,1,S,b,t,l,r));
				break;
			case 3:
				return 0;
		}
	}
}
