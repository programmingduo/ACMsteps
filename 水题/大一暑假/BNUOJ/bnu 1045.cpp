#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,a[10001],b[10000],c[10000],i,j,x,y,m,k;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>x;
		for (j=0;j<x;j++)
			cin>>a[j];
		cin>>y;
		for (j=0;j<y;j++)
			cin>>b[j];
		m=0;
		for (j=0;j<x;j++)
			for (k=0;k<y;k++)
				if(a[j]==b[k])
					c[m]=a[j], m++;
		sort(c,c+m);
		for (j=0;j<m;j++)
		{
			cout<<c[j];
			if(j!=m-1)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
