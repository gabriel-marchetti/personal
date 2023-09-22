#include <bits/stdc++.h>

using namespace std;

long long mod_exp(long long x, long long y, long long n)
{
    // Caso base:
    if ( y == 0 ) return 1;
    if ( x == 0 ) return 0;

    long long v;

    if( y % 2 == 0 ){
        v = mod_exp(x, y / 2, n);
        v = (v * v) % n;
    } 
    else {
        v = mod_exp(x, y - 1, n);
        v = ( (x % n) * v ) % n ;
    }

    // Avoid negative mod...
    return ((v + n) % n);
}

/*
 * Defining d, x0, y0 as global variables. 
*/

int d = 0, x0 = 0, y0 = 0;

void extended_euclid(int a, int b)
{
    if( b == 0 ){
        x0 = 1;
        y0 = 0;
        d  = a;
        return;
    }
    if ( b > a ) extended_euclid(b, a);
    

    extended_euclid(b, a % b);
    int x1 = y0;
    int y1 = x0 - (a/b) * y0;
    x0 = y1;
    y0 = x1;
}

