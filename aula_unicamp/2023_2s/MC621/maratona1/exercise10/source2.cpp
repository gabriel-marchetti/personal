#include <bits/stdc++.h>

using namespace std;

long sort( long array[], long size )
{
    long changes{0};
    for(long i{0}; i < size; i++)
        for(long j{size-1}; j > i; j--){
            if( array[i] < array[j] ){
                long aux;
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
                changes++;
                continue;
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
        for( long i{0}; i < n; i++ ) cin >> array[i];
        result = sort( array, n );
        cout << result << endl;
    }

    return 0;
}