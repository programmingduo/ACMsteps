#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#define maxn 10050
using namespace std;

struct yyy
{
    long long x,y;
    int c;
    bool operator < (const yyy k) const
    {
        return (x<k.x || (x==k.x && y<k.y) || (x==k.x && y==k.y && c<k.c) ) ;
    }
};

struct tree
{
    int maxx;
    int flag;
};

yyy a[4*maxn];

long long ay[2*maxn];

tree T[8*maxn];

void pushdown(int v)
{
    T[2*v].flag+=T[v].flag;
    T[2*v+1].flag+=T[v].flag;
    T[v].flag=0;
}

void pushup(int v)
{
    T[v].maxx=max(T[2*v].maxx+T[2*v].flag,T[2*v+1].maxx+T[2*v+1].flag);
}

void update(int pos,int c,int v,int L,int R)
{
    int m=(L+R)/2;

    if (pos==L) {T[v].flag+=c;return;}

    pushdown(v);
    if (pos<=m)
    {
        T[2*v+1].flag+=c;
        update(pos,c,2*v,L,m);
    }
    else
        update(pos,c,2*v+1,m+1,R);
    pushup(v);

}



int main()
{
    int i;
    int n,w,h;
    a[0].x=-1;

    while(cin>>n>>w>>h)
    {
        memset(T,0,sizeof(T));

        for (i=1;i<=2*n;i+=2)
        {
            scanf("%lld%lld%d",&a[i].x,&a[i].y,&a[i].c);
            ay[i]=a[i].y;

            a[i+1]=a[i];
            a[i+1].y+=h;
            a[i+1].c*=-1;
            ay[i+1]=a[i+1].y;

            a[2*n+i]=a[i];
            a[2*n+i].x+=w;
            a[2*n+i].c*=-1;

            a[2*n+i+1]=a[2*n+i];
            a[2*n+i+1].y+=h;
            a[2*n+i+1].c*=-1;
        }

       sort(a+1,a+4*n+1);
       sort(ay+1,ay+2*n+1);

       int num=unique(ay+1,ay+2*n+1)-ay-1;
       a[4*n+1].x=-1;

       //cout<<num<<endl;

       int ans=0;

       for (i=1;i<=4*n;i++)
       {
           int pos=lower_bound(ay+1,ay+num+1,a[i].y)-ay;

           update(pos,a[i].c,1,1,num);

           if (a[i].x!=a[i+1].x) ans=max(ans,T[1].maxx+T[1].flag);
       }

      // ans=max(ans,T[1].maxx+T[1].flag);


       cout<<ans<<endl;
    }

    return 0;
}
