#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll factorial(ll n)
{
    ll fact{1};

    for(int i{1}; i < n; i++)
        fact *= i;
    return fact;
}

ll computeAux(ll n, ll j)
{
    ll aux{1};
    for(ll i{n+j}; i > n; i--)
        aux *= i;
    return aux;
}

long double compute(long double p, int n)
{
    ll aux{0}, store{};
    for(ll i{0}; i < n; i++){
        aux += pow(1-p, i)*computeAux(n, i)/factorial(i);
    }

    return aux;
}

int main(void)
{
    int t{0}, n{0};
    long double p{0};

    cin >> t;
    for(int i{0}; i < t; i++){
        cin >> n >> p;
        p = pow(p, n)*compute(p, n);
        printf("%.2Lf\n", p);
    }

    return 0;
}