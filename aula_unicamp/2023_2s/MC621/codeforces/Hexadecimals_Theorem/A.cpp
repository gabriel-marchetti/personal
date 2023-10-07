#include <bits/stdc++.h>

using namespace std;

struct matrix{
    long long mat[2][2];
    matrix friend operator *( const matrix &a, const matrix &b ){
        matrix c;
        for( int i{0}; i < 2; i++ ){
            for( int j{0}; j < 2; j++ ){
                c.mat[i][j] = 0;
                for( int k{0}; k < 2; k++ ){
                    c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                }
            }
        }
        return c;
    }
};

matrix matpow(matrix base, long long n)
{
    matrix ans{ {
        {1, 0},
        {0, 1},
    } };
    while( n ){
        if( n & 1 )
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }

    return ans;
}

long long fib( int n ){
    matrix base{ {
        {1, 1},
        {1, 0}
    } };
    return matpow(base, n).mat[0][1];
}

int main(void){
    long long array[100];
    for(int i{0}; i < 100; i++)
        array[i] = fib(i);

    long long n;
    int index;
    cin >> n;
    for(int i{0}; i < 100; i++)
        if( n == array[i] ){
            index = i;
            break;
    }

    long long sum;
    bool flag = true;
    for(int i{0}; i < index; i++){
        sum = 0;
        for(int j{0}; j < index; j++){
            for(int k{0}; k < index; k++){
                sum = array[i] + array[j] + array[k];
                if( sum == n && array[i] != 0 && array[j] != 0 && array[k] != 0){
                    cout << array[i] <<  ' ' << array[j] << ' ' << array[k] << endl;
                    flag = false;
                    break;
                }
            }
        if( !flag ) break;
        }
    if( !flag ) break;
    }

    if(flag) cout << "I'm too stupid to solve this problem" << endl;

    return 0;
}