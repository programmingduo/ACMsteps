#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

int main()
{
    double width, height, door, workers;
    while(1)
    {
        scanf("%lf%lf%lf%lf", &width, &height, &door, &workers);
        //cin>> width>> height>> door>> workers;
        if(width == 0 )
            break;
        double danweimianji = width * height / workers;
        double zuogao = 0, yougao = 0, zuo = height, you = height;
        if(danweimianji * 2 / door < height)
        {
            zuogao = danweimianji * 2 / door;
            int temp = height / zuogao;
            zuo = height - temp * zuogao;
        }
        if(danweimianji * 2 / (width - door) <= height)
        {
            yougao = danweimianji * 2 / (width - door);
            int temp = height / yougao;
            you = height - temp * yougao;
        }
        int i = 0;
        double dingdian[105] = {0};
        dingdian[0] = (danweimianji - zuo * door / 2) * 2 / height;
        while(1)
        {
            i ++;
            dingdian[i] = dingdian[i - 1] + danweimianji * 2 / height;
            if(dingdian[i] >= width)
                break;
        }
        //cout<< fixed<<setprecision(3);
        double s = 1;
        if(yougao != 0)
        {
            s = height / yougao;
            for(int j = 1; j <= s; j ++)
            {
                printf("%.3f %.3f ", width, j * yougao);
                //cout<< width<<" "<< yougao * j<< " ";
            }
        }
        for(int j = i - 1; j > 0; j --)
        {
            printf("%.3f %.3f ", dingdian[j], height);
            //cout<< dingdian[j]<<" "<< height<<" ";
        }
        s = 1;
        if(zuogao != 0)
        {
            s = height / zuogao;
            printf("%.3f %.3f ", dingdian[0], height);
            //cout<< dingdian[0]<<" "<< height<<" ";
            for(int j = s; j > 1; j --)
            {
                printf("0.000 %.3f ", j * zuogao);
                //cout<< "0.000 "<< j * zuogao<< " ";
            }
            printf("0.000 %.3f\n", zuogao);
            //cout<< "0.000 "<< zuogao<< endl;
        }
        else
        {
            printf("%.3f %.3f\n", dingdian[0], height);
            //cout<< dingdian[0]<<" "<< height<< endl;
        }
    }
}
