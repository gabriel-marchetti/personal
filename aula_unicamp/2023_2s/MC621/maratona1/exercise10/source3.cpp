#include <bits/stdc++.h>

using namespace std;

long count( long array[], int n )
{
    long j, k, changes{0};
    bool flag;
    for(long i{0}; i < n; i++){
        if( array[i] == 0 ){
            flag = false;
            j = i - 1;
            k = i + 1;
            while( k < n ){
                if( array[k] == 1 ){
                    flag = true;
                    break;
                }
                k++;
            }
            while( array[j] != 0 && j >= 0 && flag ){
                changes++;
                j--;
            } 
        }
    }
    return changes;
}

int main(void)
{
    long t;
    long n, result;
    cin >> t;
    while( t-- ){
        cin >> n;
        long array[n];
        for(long i{0}; i < n; i++) cin >> array[i];
        result = count(array, n);

        cout << result << endl;
    }
    return 0;
}