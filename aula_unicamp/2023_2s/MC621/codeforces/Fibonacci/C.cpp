#include <bits/stdc++.h>

using namespace std;

#define MOD (1000000000+7)

struct matrix{
    long long mat[2][2];
    matrix friend operator *( const matrix &a, const matrix &b ){
        matrix c;
        for( int i{0}; i < 2; i++ )
            for( int j{0}; j < 2; j++ ){
                c.mat[i][j] = 0;
                for( int k{0}; k < 2; k++ )
                    c.mat[i][j] += ( (a.mat[i][k]%MOD)  * (b.mat[k][j]%MOD) ) % MOD; 
                    c.mat[i][j] = c.mat[i][j] % MOD;
            }
        return c;
    }
};

matrix matpow( matrix base, long long n ){
    matrix ans{ {
        {1, 0},
        {0, 1}
    } };

    while( n ){
        if( n & 1 )
            ans = ans * base;
        
        base = base * base;
        n >>= 1;
    }
    
    return ans;
}

long long fib( long long n ){
    matrix base{ {
        {1, 1},
        {1, 0}
    } };

    return matpow(base, n).mat[0][1];
}

int main(void){
    long long n;
    cin >> n;
    cout << fib(n) << endl;
}