#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t{0};
    int numA, numB, numC;
    cin >> t;
    for(int j{0}; j < t; j++){
        cin >> numA >> numB >> numC;
        if( numB % 2 == numC % 2 ){
            cout << "1 ";
        } else{
            cout << "0 ";
        }
        if( numA % 2 == numC % 2 ){
            cout << "1 ";
        } else {
            cout << "0 ";
        }
        if( numA % 2 == numB % 2 ){
            cout << "1\n";
        } else{
            cout << "0\n";
        }
    }
}