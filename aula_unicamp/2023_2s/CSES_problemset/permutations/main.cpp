#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long n;
    cin >> n;

    if( n == 1 ){
        cout << '1' << endl;
        return 0;
    }

    if( n == 4 ){
        cout << '2' << ' ' << '4' << ' ' << '1' << ' ' << '3' << endl;
        return 0; 
    }

    if( n <= 4 ){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    long long aux;
    aux = ( n % 2 ) ? n / 2 + 1 : n / 2;
    for(long long i{0}; i < aux; i++) cout << 2*i+1 << ' ';
    for(long long i{1}; i <= n / 2; i++) cout << 2*i << ' ';
    cout << endl;

    return 0;
}