#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t, sticks;
    cin >> t;
    while(t--){
        cin >> sticks;
        if( sticks % 2 )
            cout << sticks / 2 + 1 << endl;
        else
            cout << sticks / 2 << endl;
    }

    return 0;
}