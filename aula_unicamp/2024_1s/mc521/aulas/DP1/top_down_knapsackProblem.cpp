#include <bits/stdc++.h>
using namespace std;

// Global matrix of the knapSack problem.
int z[100][100];

int knapSack( int W, int w[], int c[], int n ){
    if( z[n][W] > -1 ) return z[n][W];
    if( n == 0 || W == 0 ){
        z[n][W] = 0;
        return 0;
    }
    if( w[n-1] > W ) z[n][W] = knapSack( W, w, c, n-1 );
    else z[n][W] = max( knapSack(W, w, c, n-1), knapSack(W-w[n-1], w, c, n-1) + c[n-1] );

    return z[n][W];
}

// to print the solution of the knapSack problem:
void writeSol( int n, int d, int w[] ){
    printf(">> itens in the optimal solution found: ");
    for( int k{n}; k > 0 && d > 0; --k ){
        if( z[k][d] != z[k-1][d] ){
            printf("%d ", k);
            d = d - w[k-1];
        }
    }
    printf("\n");
    return;
}

int main(){
    memset( z, -1, 100*100*sizeof(int) );


    return 0;
}