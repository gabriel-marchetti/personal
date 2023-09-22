#include <bits/stdc++.h>

using namespace std;

long long d, x_0, y_0;

void extended_euclid(long long a, long long b)
{
    if( b == 0 ){
        x_0 = 1;
        y_0 = 0;
        d  = a;
        return;
    }
    if ( b > a ) extended_euclid(b, a);
    

    extended_euclid(b, a % b);
    long long x_1 = y_0;
    long long y_1 = x_0 - (a/b) * y_0;
    x_0 = x_1;
    y_0 = y_1;
}

int main(void)
{
    long long A, B;
    while( cin >> A >> B ){
        extended_euclid(A, B);
        cout << x_0 << " " << y_0 << " " << d;
        cout << endl;
    }

}