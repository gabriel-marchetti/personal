#include <bits/stdc++.h>

/*
 * Dá problema para números grandes!
 * Tenho o método recursivo e o iterativo do método de exponenciação rápida ou
 * exponenciação binária!
*/

using namespace std;

long long binpow(long long a, long long b)
{
    if( b == 0 )
        return 1;
    long long res = binpow( a, b / 2 );
    if( b % 2 )
        return res*res*a;
    else
        return res*res;
}

long long iterative_binpow(long long a, long long b)
{
    long long res = 1;
    while( b > 0 ){
        if( b & 1 )
            res = res * a;
        a = a * a;
        b >>= 1;
    }

    return res;
}

int main(void)
{
    if( pow(3,8) == iterative_binpow(3, 8) ) printf("Correct!\n");
    else printf("Incorrect!\n");
    if( pow(2,10) == iterative_binpow(2,10) ) printf("Correct!\n");
    else printf("Incorrect!\n");
    if( pow(9,3) == iterative_binpow(9,3) ) printf("Correct!\n");
    else printf("Incorrect!\n");
    if( pow(10,15) == iterative_binpow(10,15) ) printf("Correct!\n");
    else printf("Incorrect!\n");
    if( pow(29,32) == iterative_binpow(29,32) ) printf("Correct!\n");
    else printf("Incorrect!\n");
    if( pow(91,3) == iterative_binpow(91,3) ) printf("Correct!\n");
    else printf("Incorrect!\n");
    if( pow(5,5) == iterative_binpow(5,5) ) printf("Correct!\n");
    else printf("Incorrect!\n");
    if( pow(7,28) == iterative_binpow(7,28) ) printf("Correct!\n");
    else printf("Incorrect!\n");
    if( pow(91,33) == iterative_binpow(91,33) ) printf("Correct!\n");
    else printf("Incorrect!\n");
    if( pow(12,10) == iterative_binpow(12,10) ) printf("Correct!\n");
    else printf("Incorrect!\n");
    if( pow(9,3) == iterative_binpow(9,3) ) printf("Correct!\n");
    else printf("Incorrect!\n");


    return 0;
}