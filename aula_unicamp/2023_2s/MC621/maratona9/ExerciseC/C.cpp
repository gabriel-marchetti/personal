#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        char array[n];
        cin >> array;
        
        int p1{0}, p2{n-1}, size{n};
        while( ( array[p1] == '1' && array[p2] == '0' ) || ( array[p1] == '0' && array[p2] == '1' ) ){
            size = size - 2;
            p1++;
            p2--;
        }
        if( size < 0 ) size = 0;

        cout << size << endl;
    }

    return 0;
}