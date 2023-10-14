#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long n;
    cin >> n;
    long long array[n]{0}, moves{0};
    long long p1{0}, p2{1};

    for(long long i{0}; i < n; i++) cin >> array[i]; 

    for(long long i{0}; i < n - 1; i++){
        if( array[p2] < array[p1] ){
            moves = moves + ( array[p1] - array[p2] );
            array[p2] = array[p1];
        }

        // cout << array[p1] << ' ';
        p1++; p2++;
    }
    // cout << array[p1] << endl;

    cout << moves << endl;

    return 0;
}