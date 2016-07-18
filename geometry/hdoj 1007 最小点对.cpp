#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct point
{
    double x;
    double y;
};

point p[100001];
point y[100001];

int cmpx(point a, point b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int cmpy(point a, point b)
{
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

//find_near函数是左闭又闭的
double find_near(int l, int r)
{
    if(r - l == 0)
        return 0x7fffffffffffffff;
    if(r - l == 1)
        return dis(p[l], p[r]);
//    if(r - l == 2)
//        return min(min(dis(p[l], p[l + 1]), dis(p[l], p[l + 2])), dis(p[l + 1],p[r]));
    int mid = (l + r) / 2;
    double curmin = min(find_near(l, mid), find_near(mid+1, r));
    int ith = 0;
    int i, j;
    for(int i = l; i <= r; i ++)
    {
        if(p[mid].x - p[i].x <= curmin && p[i].x - p[mid].x <= curmin)
            y[ith ++] = p[i];
    }
    sort(y, y + ith, cmpy);
    int num;
    for(i = 0; i < ith; i ++)
    {
        for(j = i + 1, num = 0; j < ith && num < 7; num ++, j ++)
            if(dis(y[i], y[j]) < curmin)
                curmin = dis(y[i], y[j]);
            else
                break;
    }
    return curmin;
}

int main ()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        for(int i =0; i < n; i ++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        sort(p, p + n, cmpx);
        //find_near函数是左闭又闭的
        printf("%.2lf\n", find_near(0, n - 1) / 2);
    }
    return 0;
}
