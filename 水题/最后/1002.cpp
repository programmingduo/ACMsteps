#include<cstdio>
#include<cmath>
using namespace std;
int main(){

    int T;
    scanf("%d", &T);
    while(T --){
        double n;
        scanf("%lf", &n);
        double ss1 = acos(1/(2*sqrt(2)));
        double sj1 = sqrt(7)/8;
        double ss2 = 4*acos(5/(4*sqrt(2)));
        double sj2 = 5*sqrt(7)/8;
        double res = 2*((ss1 - sj1) - (ss2 - sj2)) * n * n / 4;
        printf("%.2f\n", res);
    }




    return 0;
}
