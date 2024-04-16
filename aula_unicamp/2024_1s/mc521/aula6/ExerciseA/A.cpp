#include <bits/stdc++.h>
using namespace std;

int w[2020];
int c[2020];
int z[2020][2020];

int knapSack( int W, int w[], int c[], int n ){
    if( z[n][W] > - 1 ) return z[n][W];
    if( n == 0 || W == 0 ){
        z[n][W] = 0;
        return 0;
    }
    if( w[n-1] > W  ){
        z[n][W] = knapSack(W, w, c, n-1);
    }
    else{
        z[n][W] = max( knapSack(W, w, c, n-1), knapSack(W-w[n-1], w, c, n-1) + c[n-1] );
    }

    return z[n][W];
}

void printArray( int n, int arr[] ){
    for(int i{0}; i < n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printMatrix( int n, int W , int matrix[2020][2020] ){
    for(int i{0}; i <= n; ++i){
        for(int j{0}; j <= W; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main( ){
    int W, N;
    memset( z, -1, 2020 * 2020 * sizeof(int) );
    cin >> W >> N;
    for( int i{0}; i < N; ++i ){
        int tmp_cost, tmp_weight;
        cin >> tmp_weight >> tmp_cost;
        c[i] = tmp_cost;
        w[i] = tmp_weight;
    }
    //printf("%d\n", N);
    //printArray(N, w);
    //printArray(N, c);

    printf("%d\n", knapSack(W, w, c, N));
    //printMatrix(N, W, z);

    return 0;
}