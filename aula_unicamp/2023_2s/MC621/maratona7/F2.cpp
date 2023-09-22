#include <bits/stdc++.h>

using namespace std;


void matrix_mult(long long A[2][2], long long B[2][2], long long C[2][2], long long M)
{
    C[0][0] = (((A[0][0] % M)*(B[0][0] % M) % M)  + ((A[0][1] % M )*( B[1][0] % M)%M)) % M;
    C[0][1] = (((A[0][0] % M)*(B[0][1] % M) % M)  + ((A[0][1] % M )*( B[1][1] % M)%M)) % M;
    C[1][0] = (((A[1][0] % M)*(B[0][0] % M) % M)  + ((A[1][1] % M )*( B[1][0] % M)%M)) % M;
    C[1][1] = (((A[1][0] % M)*(B[0][1] % M) % M)  + ((A[1][1] % M )*( B[1][1] % M)%M)) % M;
}

void matrix_exp(long long A[2][2], long long R[2][2], long long n, long long M)
{
    if(n == 1){
        R[0][0] = 1;
        R[0][1] = 0;
        R[1][0] = 0;
        R[1][1] = 1;
    } 

    if( n % 2 == 0 ){
        matrix_exp(A, R, n/2, M);
        matrix_mult(R, R, R, M);
    }
    else{
        matrix_mult(A, , R, M);
    }
}

int main(void)
{
    int T;
    cin >> T;
    int i;
    long long a, b, n, M;
    long long A[2][2];
    long long f[2];
    for(i = 0; i < T; i++){
        cin >> a >> b >> n >> M;
        A[0][0] = a % M;
        A[0][1] = 1;
        A[1][0] = 0;
        A[1][1] = b % M;

        f[0] = 1;
        f[1] = b;
        A = matrix_exp(A, n);
        
        long long resposta = ( (A[0][0] % M) + (A[0][1] * (b%M)) % M ) % M;

        
    }
    return 0;
}