#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)
int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        double r, h, d;
        double v, s;
        scanf("%lf%lf%lf", &r, &h, &d);
        v = PI*PI*r*d*d + 4.0/3*PI*d*d*d + 2*PI*r*r*d + PI*h*((d + r)*(d + r));
        s = 2*(PI*PI*r*d + 2*PI*d*d + PI*r*r + PI*h*(r + d));
        printf("%.12lf %.12lf\n", v, s);

    }
    return 0;
}
