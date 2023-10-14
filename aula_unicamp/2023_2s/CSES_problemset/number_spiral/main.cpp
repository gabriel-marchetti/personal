#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll deviate( ll greater, ll x, ll y )
{
    if( greater % 2 ){
        // greater is odd;
        return x - y;
    } else {
        // greater is even;
        return y - x;
    }
}

int main(void)
{
    ll t{0};
    cin >> t;

    ll x, y;
    ll greater, upper_bound, middle, deviation;    
    while( t-- ){
        cin >> y >> x;
        greater = ( x > y ) ? x : y;

        upper_bound = greater * greater;
        middle = upper_bound - greater + 1;
        deviation = deviate(greater, x, y);

        cout << middle + deviation << endl;
    }

    return 0;
}