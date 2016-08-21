#include <cstdio>
#include <cmath>

using namespace std;

long long po[100];

int main()
{
    po[0] = 1;
    for(int i = 1; i <= 35; i ++){
        po[i] = po[i-1] * 2;
    }
    long long n;
    scanf("%lld", &n);
    for(int i = 0; po[i] < n; i ++){
        if(i)
            printf(" ");
        printf("%lld", po[i]);
    }
    printf("\n");

//    main();
	return 0;
}
