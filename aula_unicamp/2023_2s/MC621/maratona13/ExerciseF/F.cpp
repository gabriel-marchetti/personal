#include <bits/stdc++.h>

using namespace std;

int main(void){
    vector<long long> sticks{0};
    int t;
    cin >> t;
    long long aux;
    bool flag = true;
    for( int i{0}; i < t; i++ ){
        cin >> aux;
        sticks.push_back(aux);
    }
    sort(sticks.begin(), sticks.end());

    for(auto i{sticks.size()-1}; i >= 2; i--){
        long long a = sticks[i],
                  b = sticks[i-1],
                  c = sticks[i-2];
        if( a < (b + c) && b < (a + c) && c < (a + b) ){
            cout << "possible" << endl;
            flag = false;
            break;
        }
    }
    if(flag) cout << "impossible" << endl;

    return 0;
}