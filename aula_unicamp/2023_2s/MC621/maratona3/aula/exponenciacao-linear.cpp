#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll potencia(ll x, ll p)
{
    if (p == 0){
        return 1;
    } else {
        return x * potencia(x, p-1);
    }
}

int main()
{
    ll x{}, p{}, result{};
    cin >> x >> p;

    result = potencia(x, p);

    cout << result << '\n';

    return 0;
}