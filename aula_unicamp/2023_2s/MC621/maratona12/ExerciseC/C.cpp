#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n{0};
    cin >> n;
    double w[n], b, aux;
    double norm_w{0};
    for(int i{0}; i < n; i++){
        cin >> aux;
        w[i] = aux;
        norm_w = norm_w + aux*aux;
    }
    norm_w = sqrt(norm_w);
    cin >> b;
    double scanner{0}, d_x{0};
    cin.ignore(1);
    while( cin.peek() != EOF ){
        d_x = 0;
        for( int j{0}; j < n; j++){
            cin >> scanner;
            d_x += w[j]*scanner;
            //cout << scanner << ' ';
        }
        //cout << endl;
        d_x = d_x + b;
        d_x = d_x / norm_w;
        cout << setprecision(6) << d_x << endl;
        cin.ignore(1);
    }

    return 0;
}