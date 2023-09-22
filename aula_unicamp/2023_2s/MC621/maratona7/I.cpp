#include <bits/stdc++.h>

using ll = long long;
using namespace std;
#define MOD 998244353

ll fast_exp(ll a, ll n)
{
    if(n == 0) return 1;
    if(a == 0) return 0;

    ll aux;
    if(n % 2 == 0){
        aux = ( (fast_exp(a, n / 2) % MOD) * (fast_exp(a, n / 2) % MOD) % MOD);
        return aux;  
    }
    else{
        aux = ((a % MOD)*(fast_exp(a, n-1) % MOD)) % MOD;
        return aux; 
    }
}

int main(void)
{
    long long w, h;
    cin >> w >> h;
    ll total;
    total = ((fast_exp(2, w)  % MOD)*(fast_exp(2, h) % MOD)) % MOD;
    cout << total << '\n';

    return 0;
}