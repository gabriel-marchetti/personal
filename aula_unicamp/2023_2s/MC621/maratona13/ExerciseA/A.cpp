#include <bits/stdc++.h>
#define PI acos(-1.0)

using namespace std;

int main(void){
    double radius, area, estimatedArea;
    double m, c;
    while( cin >> radius >> c >> m ){
        if( radius == 0 && m == 0 && c == 0 ) break;

        area = PI * radius * radius;
        //cout << "r:" << radius << ' ' << "m:" << m << ' ' << "c:" << c << endl;
        estimatedArea =  4 * (m / c) * radius * radius;

        cout << setprecision(12);
        cout << area << ' ' << estimatedArea << endl;
    }

    return 0;
}