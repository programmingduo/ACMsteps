#include<cstdio>
#include<cmath>

int main ()
{
    double ax, bx, cx, ay, by, cy, a, b, c, cos, sin, r;
    while(~scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy))
    {
        a = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
        b = sqrt((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy));
        c = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
        cos = (a * a + b * b - c * c) / (2 * a * b);
        sin = sqrt(1 - cos * cos);
        r = c / sin;
        printf("%.2lf\n", 3.141592653589793 * r);
    }
    return 0;
}
