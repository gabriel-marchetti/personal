#include <bits/stdc++.h>

using namespace std;

long long resolve(long long a, long long b, long long n, long long M)
{
    if ( n == 0 ) return 1;
    return ( ((a % M) * (resolve(a, b, n - 1,  M)) % M) + b % M ) % M;
}


int main(void)
{
    int T;
    cin >> T;
    long long a, b, n, M;
    long long resposta;
    int i; //Counter
    for(i = 0; i < T; i++){
        cin >> a >> b >> n >> M;
        resposta = resolve(a, b, n, M);
        cout << resposta << '\n';
    }

    return 0;
}