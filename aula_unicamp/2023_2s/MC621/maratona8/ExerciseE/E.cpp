#include <bits/stdc++.h>

#define phi pow(2.0, 0.5) + pow(3.0, 0.5) + pow(6.0, 0.5)

using namespace std;

double F( int n )
{
    if ( n == 0 ) return phi;

    double val = F(n-1);
    return ( ( pow(val, 2) - 5 ) / (2 * val + 4 ) );
}

int main(void)
{
    long long N;
    cin >> N;
    while( cin >> N ){
        cout << F(N) << endl;
    }

    return 0;
}