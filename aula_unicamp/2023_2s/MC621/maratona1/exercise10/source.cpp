#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long t;
    long n;
    cin >> t;
    while( t-- ){
        cin >> n;
        long array[n];
        for( long i{0}; i < n; i++ ) cin >> array[i];

        long changes{0}, in_a_row{0};
        for(long i{0}; i < n - 1; i++){
            if( array[i] == 1 && array[i+1] == 1 ) in_a_row++;
            if( array[i] == 1 && array[i+1] == 0 ) changes = changes + in_a_row + 1;
            if( array[i] == 0 && array[i+1] == 0 ) in_a_row = 0;
            if( array[i] == 0 && array[i+1] == 1 ) in_a_row = 0;
        }
                
        cout << changes << endl;
    }

    return 0;
}