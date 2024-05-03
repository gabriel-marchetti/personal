#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> cowbells;
    // Adding virtual cowbells;
    for( int i{0}; i < 2*k - n; ++i ){
        cowbells.push_back(0);
    }
    
    for( int i{0}; i < n; ++i ){
        int tmp;
        cin >> tmp;
        cowbells.push_back(tmp);
    }

    int max_box_size = -1;
    auto begin = cowbells.begin(),
         end = cowbells.end() - 1;
    
    // for( auto val : cowbells ){
    //     cout << val << ' ';
    // } cout << endl;

    int sum;
    for( int i{0}; i < cowbells.size() / 2; ++i ){
        // cout << *begin << endl;
        // cout << *end << endl;
        sum = *begin + *end;
        if( sum > max_box_size ) max_box_size = sum;
        begin++; end--;
    }
    cout << max_box_size << endl;

    return 0;
}