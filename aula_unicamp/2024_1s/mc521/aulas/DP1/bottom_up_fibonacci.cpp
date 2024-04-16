#include <bits/stdc++.h>
using namespace std;

int fib( int n ){
    int valor[n+1];
    valor[0] = 0; valor[1] = 1;

    for( int i{2}; i <= n; ++i ){
        valor[i] = valor[i-1] + valor[i-2];
    }

    return valor[n];
}

int main(){
    int n;
    scanf("%d", &n);
    printf("fib(%d) = %d\n", n, fib(n)); 

    return 0;
}