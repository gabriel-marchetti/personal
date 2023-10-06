#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long n)
{
    if ( n == 2 || n == 3 )
        return false;
    
    if ( n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for ( long long i{0}; i * i <= n; i+=6 ){
        if ( n % i == 0 || n % ( i + 2 ) == 0 )
            return false;
    }

    return true;
}

bool is_happy(long long n)
{
    if( n <= 1 ) return false;
    long long aux{0};
    long long remainder, division;
    while ( n > 1 ){
        remainder = n % 10;
        division  = n / 10;
        aux      += remainder * remainder;
        if( division == 0 ){
            n   = aux;
            aux = 0;
        }
        if( n == 1  ) return true;
    }
    
    return false;
}

int main(void)
{
    int P;
    long long m, iter;
    bool prime, happy;

    cin >> P;
    while( P-- ){
        cin >> iter >> m;

    }


    return 0;
}