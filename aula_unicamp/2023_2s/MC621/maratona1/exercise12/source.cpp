#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long n;
    string telephone_number;
    cin >> n >> telephone_number;
    long long n_eigth{0}, rounds{0};

    rounds = n - 11;
    for(long long i{0}; i <= rounds; i++){
        if( telephone_number[i] == '8' ) n_eigth++;
    }

    if( n_eigth > rounds / 2 ) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}