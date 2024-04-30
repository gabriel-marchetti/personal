#include <bits/stdc++.h>
#define MAX_N 200010
#define MAX_VAL 1000000010
using namespace std;

long long A[MAX_N], DP[MAX_N];

/* MAX SUBARRAY SUM */
long long MSS( int n ){
    DP[1] = A[1];
    long long MAX_MSS = A[1];
    for( int i = 2; i <= n; ++i ){
        DP[i] = max( A[i], DP[i-1] + A[i] );
        MAX_MSS = max(MAX_MSS, DP[i]);
    }

    return MAX_MSS;
}

int main(){
    int n;
    cin >> n;
    for( int i = 1; i <= n; ++i ){
        int tmp;
        cin >> tmp;
        A[i] = tmp;
    }
    
    cout << MSS(n) << endl;

    // for( int i = 1; i <= n; ++i ){
    //     printf("%lld ", DP[i]);
    // } printf("\n");
    

    return 0;
}