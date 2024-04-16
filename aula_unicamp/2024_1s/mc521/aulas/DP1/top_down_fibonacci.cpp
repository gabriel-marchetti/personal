#include <bits/stdc++.h>
using namespace std;

// DP-memory for fibonacci numbers
int memo[101];

int fib( int n ){
    if( n < 2 ) return n;
    else if( memo[n] >= 0 ) return memo[n];
    return memo[n] = fib( n-1 ) + fib( n-2 );
}

int main(){
    int n;
    scanf("%d", &n);
    memset( memo, -1, sizeof(memo) );
    printf("fib(%d) = %d\n", n, fib(n));

    return 0;
}