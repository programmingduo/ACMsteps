#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define eps 1e-6
#define s1 s[0]
#define s2 s[1]
#define s3 s[2]
#define s4 s[3]
double f(double a, double b, int k)
{
	switch (k)
	{
		case 1:
			return a + b;
		case 2:
			return a - b;
		case 3:
			return a * b;
		case 4:
			return a/b;
	}
}
double f1(char c)
{
	switch (c)
	{
		case 'A':
			return 1;
		case 'J':
			return 11;
		case 'Q':
			return 12;
		case 'K':
			return 13;
		case '0':
            return 10;
		default : return c - '0';

	}
}
double s[4];
int main()
{
	char c[5];
	int t, i, j, k, flag;
	cin>>t;
	while (t--)
	{
		flag = 0;
		for (i = 0; i < 4; i++)
		{
			cin>>c;
			s[i] = f1(c[0]);
		}
		sort(s,s+4);
		do
		{
			for (i = 1; i <= 4; i++)
				for (j = 1; j <=4; j++)
					for (k = 1; k <=4; k++)
					{
						if (
						abs(f(f(f(s1,s2,i),s3,j),s4,k) - 24) < 0.00000001||
						abs(f(s1,f(f(s2,s3,i),s4,j),k) - 24) < 0.00000001||
						abs(f(f(s1,f(s2,s3,i),j),s4,k) - 24) < 0.00000001||
						abs(f(s1,f(s2,f(s3,s4,i),j),k) - 24) < 0.00000001||
						abs(f(f(s1,s2,i),f(s3,s4,j),k) - 24) < 0.00000001
						)
						{
							flag = 1;
							goto leb;
						}

					}
		}while(next_permutation(s,s+4));
leb:;
		if(flag)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
	return 0;
}
