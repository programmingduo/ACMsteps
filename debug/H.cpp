#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int t;
double l, r, vl, vr, s;
#define PI acos(-1.0)

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%lf %lf %lf %lf %lf", &l, &r, &vl, &vr, &s);
        bool flag = false;
        if(vl < vr){
            flag = true;
            swap(vl, vr);
        }
        double dv = vl - vr;
        if(dv != 0){
            double lpie = (vr*l)/(dv);
            double hu = vr*s*2.0*PI*r;
            cout << "hu=" << hu << endl;
            cout << "lpie = " << lpie << endl;
            cout << "zhouchang" << 2.0*PI*lpie << endl;
            double ressin = sin(hu / (2.0 * PI * lpie));
            double rescos = cos(hu / (2.0 * PI * lpie));
            double ansy = (l/2.0 + lpie) * ressin;
            double ansx = (l/2.0 + lpie) * (1.0-rescos);
            if(!flag)
                printf("%.3lf %.3lf\n", ansx, ansy);
            else printf("%.3lf %.3lf\n", -1.0*ansx, -1.0*ansy);
        }
        else{
            printf("0.000 %.3lf\n", 2.0*r*PI*s);
        }
    }
    return 0;
}
