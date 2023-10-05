#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long t, n, sum{0};
    long long aux, aux2;
    cin >> t;
    while(t--){
        sum = 0;
        cin >> n;
        for(int i{0}; i < n; i++){
            cin >> aux;
            sum += aux;
        }
        aux2 = sum % n;
        cout << aux2 * (n - aux2) << endl;
    }

    return 0;
}