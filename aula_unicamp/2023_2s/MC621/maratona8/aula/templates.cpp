#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f(ll x0)
{
    // Define function for iterating.
    return x0;
}

/*
 * Algumas observações sobre a estrutura pair.
 * Ela serve para relacionar duas estruturas de dados de tipagem diferente.
 * Podemos inicializar algo como pair<string, double> = p2("Hello", 3.14)
 * Para acessar seus elementos basta fazer p2.first ou p2.second
 */

pair<int, int> floyd_cycle_finding(int x0)
{
    int tortoise = f(x0);
    int hare     = f(f(x0));
    while( tortoise != hare ){
        tortoise = f(tortoise);
        hare     = f(f(hare));
    }
    int mu, hare = x0;
    while( tortoise != hare ){
        tortoise = f(tortoise);
        hare     = f(hare);
        mu++;
    }

    int lambda = 1;
    int hare = f(tortoise);

    while( tortoise != hare ){
        hare = f(hare);
        lambda++;
    }

    return make_pair(mu, lambda);
}
