#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct node
{
    int z;
    double x, y;
}point[200005], p[200005];

int cmpx(node a, node b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int cmpy(node a, node b)
{
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

double dis(node a, node b)
{
    if(a.z == b.z)
        return 0x7fffffffffffffff;
    double xx = a.x - b.x;
    double yy = a.y - b.y;
    return sqrt(xx * xx + yy * yy);
}

//find_near函数是左闭又闭的
double find_near(int l, int r)
{
    if(l == r)
        return 0x7fffffffffffffff;
    if(l == r - 1)
        return dis(point[l], point[r]);
//    if(l == r - 2)
//        return min(min(dis(point[l], point[l + 1]), dis(point[r - 1], point[r])), dis(point[l], point[r]));
    int mid = (l + r) >> 1;
    double mindis = min(find_near(l, mid), find_near(mid + 1, r));
    int ith = 0;
    for(int i = l; i <= r; i ++)
    {
        if(point[i].x - point[mid].x < mindis && point[mid].x - point[i].x < mindis)
            p[ith ++] = point[i];
    }
    sort(p, p + ith, cmpy);
    for(int i = 0; i < ith; i ++)
    {
        for(int j = i + 1, num = 0; j < ith && num < 7; j ++, num ++)
        {
            mindis = min(mindis, dis(p[i], p[j]));
        }
    }
    return mindis;
}

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
        {
            scanf("%lf%lf", &point[i].x, &point[i].y);
            point[i].z = 0;
        }
        int temp = n * 2;
        for(int i = n; i < temp; i ++)
        {
            scanf("%lf%lf", &point[i].x, &point[i].y);
            point[i].z = 1;
        }
        sort(point, point + temp, cmpx);
        //find_near函数是左闭又闭的
        printf("%.3f\n", find_near(0, temp - 1));
    }
    return 0;
}
