#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int main(void){
    double a, b, c;
    while( cin >> a >> b >> c ){
        if( a == 0 && b == 0 && c == 0 ) break;

        double alpha = acos( ( b*b + c*c - a*a ) / ( 2*b*c ) ),
               beta = acos( ( a*a + c*c - b*b ) / ( 2 * a * c ) ),
               gamma = acos( ( a*a + b*b - c*c ) / ( 2 * a * b ) );

        if( fabs(alpha - PI/2) < EPS || fabs(beta - PI/2) < EPS || fabs(gamma - PI/2) < EPS ){
            cout << "right" << endl;
        } else {
            cout << "wrong" << endl;
        }
    }


    return 0;
}