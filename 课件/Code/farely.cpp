#include<iostream>
using namespace std;

struct node {int m,n;};
struct ans{
    int v,lc;
    node nd;
    }as[5000];
int lim,total,k,t;

void getorder(node pr,node nt,int &num,int pren)
{
    int m,n;
	m=pr.m+nt.m;
	n=pr.n+nt.n;
	num=0;
	if (m<=n && m<=lim && n<=lim){
        num++;
        int lf,rg;
        node mid;
        mid.m=m,mid.n=n;
        getorder(pr,mid,lf,pren);
        while(pren+lf+2==as[k].v && k<t)
            as[k++].nd=mid;
        getorder(mid,nt,rg,pren+lf+1);
        num+=lf+rg;
	}
}

int cmp1(ans const &a,ans const &b)
{
    return a.v<b.v;
}

int cmp2(ans const &a,ans const &b)
{
    return a.lc<b.lc;
}

int main()
{
    node begin,end;
    begin.m=0,begin.n=1;
    end.m=1,end.n=1;
    while(scanf("%d%d",&lim,&t)!=EOF){
        for(int i=0;i<t;i++)cin>>as[i].v,as[i].lc=i;
        sort(as,as+t,cmp1);
        k=0;
        int total,num;
        while(as[k].v==1 && k<t)as[k++].nd=begin;
        getorder(begin,end,num,0);
        total=num+2;
        sort(as,as+t,cmp2);
        for(int i=0;i<t;i++){
            if (as[i].v==total)cout<<"1/1"<<endl;
                else {
                    if (as[i].v>total)cout<<"No Solution"<<endl;
                            else    cout<<as[i].nd.m<<'/'<<as[i].nd.n<<endl;
                    }
        }
	}
	return 0;
}
