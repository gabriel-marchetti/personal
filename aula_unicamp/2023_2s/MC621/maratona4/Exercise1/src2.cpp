#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX_DIGITS 30
#define PLUS       1
#define MINUS      -1

typedef struct{
    char digits[MAX_DIGITS];
    int signbit;
    int lastdigit;   
} big_number;

/* Defining functions */
void ll_2_bignum(ll s, big_number *n);
int compare_bignum(big_number *a, big_number *b);
void left_shift(big_number *n, int d);
void zero_justify(big_number *n);
void initialize_bignum(big_number *a);
void add_bignum(big_number *a, big_number *b, big_number *c);
void subtract_bignum(big_number *a, big_number *b, big_number *c);
void multiply_bignum(big_number *a, big_number *b, big_number *c);
void print_bignum(big_number *a);
/*--------------------*/

void ll_2_bignum(ll s, big_number *n)
{
    int i;  /* Counter */
    ll t;

    if ( s >= 0 ) n->signbit = PLUS;
    else n->signbit = MINUS;

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

int compare_bignum(big_number *a, big_number *b)
{
    /*
     *   return -1, if a > b
     *   return 0, if a == b
     *   return 1, if a < b
    */
    int i;

    if( (a->signbit == MINUS) && (b->signbit) == PLUS ) return 1;
    if( (a->signbit == PLUS) && (b->signbit == MINUS) ) return -1;
 
    if( a->lastdigit > b->lastdigit ) return ( MINUS * a->signbit );
    if( b->lastdigit > a->lastdigit ) return ( PLUS * a->signbit );

    /*
     * Can do a loop-for with a->lastdigit, since they are equal.
     * I checked this right above.
    */
    for( i = a->lastdigit; i >= 0; i--){
        if( a->digits[i] > b->digits[i] ) return ( MINUS * a->signbit);
        if( b->digits[i] > a->digits[i] ) return ( PLUS * a->signbit);
    }

    return(0);
}

void left_shift(big_number *n, int d)
{
    /* d is used to multiply by 10^d, since left shift is equivalent to that. */
    int i; /* Counter */

    if( ( n->lastdigit == 0 ) && (n->digits[0] == 0) ) return;

    for( i = n->lastdigit; i >= 0; i--){
        n->digits[i+d] = n->digits[i];
    }

    for( i = 0; i < d; i++) n->digits[i] = 0;

    n->lastdigit = n->lastdigit + d;
}

void zero_justify(big_number *n)
{

    while( (n->lastdigit > 0) && ( n->digits[n->lastdigit] == 0 ) )
        n->lastdigit--;
    
    if( (n->lastdigit == 0) && ( n->digits[0] == 0 ) )
        n->signbit = PLUS; /* Avoid -0 */
}

void initialize_bignum(big_number *a)
{
    a->signbit = PLUS;
    for(int i{0}; i < MAX_DIGITS; i++){
        a->digits[i] = (char) 0;
    }
}

void add_bignum(big_number *a, big_number *b, big_number *c)
{
    int i, carry;
    initialize_bignum(c);

    if( a->signbit == b->signbit ) c->signbit = a->signbit;
    else{
        // Sinais opostos.
        if( a->signbit == MINUS ){
            a->signbit = PLUS;
            subtract_bignum(b, a, c);
            a->signbit = MINUS;
        } else {
            b->signbit = PLUS;
            subtract_bignum(a, b, c);
            b->signbit = MINUS;
        }
        return;
    }

    c->lastdigit = max(a->lastdigit, b->lastdigit);
    carry = 0;

    for(int i{0}; i <= (c->lastdigit); i++){
        c->digits[i] = (char) (carry + a->digits[i] + b->digits[i] ) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }

    zero_justify(c);
}

void subtract_bignum(big_number *a, big_number *b, big_number *c)
{
    int borrow, v, i;
    /*
     * borrow: Has anything been borrowed?
     * v: placeholder digit
     * i: Counter
    */

    initialize_bignum(c);

    if( ( a->signbit == MINUS ) || ( b->signbit == MINUS ) ){
        b->signbit = MINUS * b->signbit;
        add_bignum(a, b, c);
        b->signbit = MINUS * b->signbit;
        return;
    }

    if( compare_bignum(a, b) == PLUS ){
        subtract_bignum(b, a, c);
        c->signbit = MINUS;
        return;
    }

    c->lastdigit = max(a->lastdigit, b->lastdigit);
    borrow = 0;

    for( i = 0; i <= c->lastdigit; i++ ){
        v = (a->digits[i] - b->digits[i] - borrow);
        if ( a->digits[i] > 0 ) borrow = 0;
        if ( v < 0 ){
            v = v+10;
            borrow = 1;
        }
        c->digits[i] = (char) v;
    }

    zero_justify(c);
}

void multiply_bignum(big_number *a, big_number *b, big_number *c)
{
    big_number row, tmp;
    int i, j;

    initialize_bignum(c);
    
    row = *a;
    
    for(i = 0; i <= b->lastdigit; i++){
        for( j = 1; j <= b->digits[i]; j++){
            add_bignum(c, &row, &tmp);
            *c = tmp;
        }
        left_shift(&row, 1);
    }

    c->signbit = a->signbit * b->signbit;

    zero_justify(c);
}

void print_bignum(big_number *a)
{
    for(int i{a->lastdigit}; i >= 0; i--){
        cout << a->digits[i];
    }
}

int main(void)
{
    int N{0}, F{0};
    ll item_aux{0};
    int bill{1};
    big_number total{0}, item{0}, total_aux{0};
    initialize_bignum(&total), initialize_bignum(&item), initialize_bignum(&total_aux);

    do
    {
        initialize_bignum(&total); initialize_bignum(&item);
        cin >> N >> F;
        for(int i{0}; i < N; i++){
            cin >> item_aux;
            ll_2_bignum(item_aux, &item);
            add_bignum(&total_aux, &item, &total);
            total_aux = total;
        }

        print_bignum(&total);
        
        bill++;
    } while ( N != 0 || F != 0 );
    

    return 0;
}