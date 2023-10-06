#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    double F0 = sqrt(2) + sqrt(3) + sqrt(6);
    cout << F0 << endl;
    for( int i = 0; i < 10; i++ ){
        F0 = ( F0 * F0 - 5 )/(2 * F0 + 4);
        cout << F0 << endl;
    }

}