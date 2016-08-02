#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
using namespace std;

const int N=10002;
int n;
vector<int> vec[N];
int id[N],pre[N],low[N],s[N],stop,cnt,scnt;
int ans;

//pre 记录哪个没有遍历
void tarjan(int v)
{
    int t,minc=low[v]=pre[v]=cnt++;
    vector<int>::iterator pv;
    s[stop++]=v;
    for(pv=vec[v].begin();pv!=vec[v].end();++pv){
        if(-1==pre[*pv])tarjan(*pv);
        if(low[*pv]<minc)minc=low[*pv];
    }
    if(minc<low[v]){
        low[v]=minc;return;
    }
    do{
        id[t=s[--stop]]=scnt;low[t]=n;
    }while(t!=v);
    ++scnt;
}
int main()
{
    int i,m;
    while(cin>>n>>m){
        for(i=0;i<=n;i++){
            vec[i].clear();
        }
        stop=cnt=scnt=0;
        memset(pre,-1,sizeof(pre));
        for(i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            vec[a].push_back(b);
        }
        //vector[a] = b意思是由a指向b

        for(i=0;i<n;++i){
            if(pre[i]==-1)
                tarjan(i);
        }
        if(scnt==1){
            printf("%d\n",n);
        }
        else{
            ans=0;
            int out[N];
            memset(out,0,sizeof(out));
            vector<int>::iterator pv;
            for(i=0;i<n;i++){
                for(pv=vec[i].begin();pv!=vec[i].end();++pv){
                    if(id[i]!=id[*pv]){
                        out[id[i]]++;
                    }
                }
            }
            int k=0,count=0;
            for(i=0;i<scnt;i++){
                if(out[i]==0){
                    ans++;
                    k=i;
                }
            }
            if(ans==1){
                for(i=0;i<n;i++){
                    if(id[i]==k){
                        count++;
                    }
                }
                printf("%d\n",count);
            }
            else printf("0\n");
        }
    }
    return 0;
}
