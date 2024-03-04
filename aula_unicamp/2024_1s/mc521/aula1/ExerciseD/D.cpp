#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int aux;

    if( b / m < a ){
        int reminder = (n % m) * a;
        if( b < reminder ){
            aux = (n / m) * b + b;
        } else {
            aux = (n / m) * b + reminder;
        }
        
    } else {
        aux = n * a;
    }

    cout << aux << endl;

    return 0;
}