#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define MAX_DIGITS 1000

typedef struct{
    char digits[MAX_DIGITS];
    int lastdigit;
} number;


void ll_2_bignum(ll s, number *n)
{
    int i;  /* Counter */
    ll t;

    for(i = 0; i < MAX_DIGITS; i++) (n->digits)[i] = (char) 0;
    n->lastdigit = -1;

    t = (s >= 0) ? s : -s;  
    while ( t > 0 ){
        n->lastdigit ++;
        n->digits[n->lastdigit] = char (t % 10);
        t = t / 10;    
    }

    if ( s == 0 ) n->lastdigit = 0;
}


int main()
{
    int t{0};
    number num{};

    

    return 0;
}