#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main ()
{
    float diameters, time, distance, speed;
    int rand, number = 0;
    while(cin>> diameters>> rand>> time)
    {
        if(rand == 0)
            break;
        number ++;
        distance = 3.1415927 * diameters * rand;
        distance /= (5280 * 12);
        time /= 3600;
        speed = distance / time;
        cout<< "Trip #"<< number<< ": ";
        cout<< fixed<< setprecision(2);
        cout<< distance<< " "<< speed<< endl;
    }
    return 0;
}
