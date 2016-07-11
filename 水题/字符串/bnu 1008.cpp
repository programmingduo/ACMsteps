#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

char s[10000], c[100], d[4]= "IUP", dw[4]= "AVW";
double o[4];

double f(char cc)
{
	switch (cc)
	{
		case 'm': return 0.001;
		case 'k': return 1000;
		case 'M': return 1000000;
		default : return 1;
	}
}

int main()
{
	int n, i, k, j, l, t;
	cin >> n; getchar();
	for(k= 0; k< n; k++)
	{
		memset(s, 0, sizeof(s));
		fgets(s, sizeof(s), stdin);
		l= strlen(s);
		memset(o, 0, sizeof(o));
		for(i= 0; i< l; i++)
			for(t= 0; t< 4; t++)
				if(s[i]== d[t] && s[i+ 1]== '=')
				{
					j= i+ 2;
					memset(c, 0, sizeof(c));
					while(s[j]!= dw[t]) { c[j -i- 2]= s[j]; j++; }
					double v= f(s[j- 1]), sh;
					if(fabs(v- 1)< 1e-9) c[j- 1]= 0;
					sscanf(c, "%lf", &sh);
					o[t]= sh* v;
				}
		printf("Problem #%d\n", k+ 1);
		if(fabs(o[0]- 0)< 1e-9) printf("I=%.2lfA\n", o[2]/o[1]);
		if(fabs(o[1]- 0)< 1e-9) printf("U=%.2lfV\n", o[2]/o[0]);
		if(fabs(o[2]- 0)< 1e-9) printf("P=%.2lfW\n", o[1]*o[0]);
		cout << endl;
	}
	return 0;
}
