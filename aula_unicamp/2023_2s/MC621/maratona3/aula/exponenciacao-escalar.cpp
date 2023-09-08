#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll potencia_escalar(ll x, ll p)
{
    ll aux{};
    if ( p == 0 ){
        return 1;
    } else if ( p % 2 == 0 ){
        aux = potencia_escalar( x, p/2 );
        return aux*aux;
    } else {
        aux = potencia_escalar( x, (p-1)/2 );
        return x*aux*aux;
    }
}

int main()
{
    ll x{}, p{}, value{};
    cin >> x >> p;

    value = potencia_escalar(x, p);
    cout << value << '\n';

    return 0;
}