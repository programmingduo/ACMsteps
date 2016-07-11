#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const double eps=1e-6;
struct node
{
    double x, y;
} Map[105];
int main()
{
    int i,j;
    double w,h,door,worker;
    while(~scanf("%lf%lf%lf%lf",&w,&h,&door,&worker),(w+h+door+worker))
    {
        double sum=w*h;          //�����
        double s=sum/worker;     //ÿ�鷿������
        double res=0.0;          //
        for(i=0; i<worker-1; i++)
        {
            res+=s;
            if(res<=(w-door)*h/2.0) //�߽��ұߵ�����
            {
                Map[i].x=w;       //����ó���
                Map[i].y=res*2.0/(w-door);
            }
            else if(res<=(2*w-door)*h /2.0) //�߽���ߵ�����
            {
                Map[i].x=w-(res*2.0/h-w+door);
                Map[i].y=h;
            }
            else //�������б߽���
            {
                double ress=sum-res;//ʣ�����
                Map[i].x=0;
                Map[i].y=ress*2.0/door;
            }
        }
        for(i=0; i<worker-1; i++)
        {
            if(i) printf(" ");
            printf("%.3lf %.3lf",Map[i].x,Map[i].y);
        }
       printf("\n");
    }
    return 0;
}
