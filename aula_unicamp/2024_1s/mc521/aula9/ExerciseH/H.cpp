#include <bits/stdc++.h>
using namespace std;

void solve( vector<int>& zerosPos, long long k ){
    int max_val{0};
    auto index = zerosPos.begin();
    while( k > 0 && index != zerosPos.end() ){
        int diff = *index - max_val;
        if( diff <= k ){
            k -= diff;
            *index = max_val;
        }
        else{
            *index = *index - k;
            k = 0;
        }

        max_val++;
        index++;
    }
}

int main(){
    int t;
    cin >> t;
    while( t-- ){
        long long n, k;
        vector<int> zerosPos;
        string binStr;
        zerosPos.clear();
        cin >> n >> k;
        cin >> binStr;
        for( int i{0}; i < binStr.size(); ++i ){
            if( binStr[i] == '0' ) zerosPos.push_back(i);
        }
        solve(zerosPos, k);
        vector<int> finalBin;
        finalBin.resize(n);
        finalBin.assign(n, 1);
        for( auto index : zerosPos ){
            finalBin[index] = 0;
        }

        for( auto index : finalBin ){
            cout << index;
        }cout << endl;

    }

    return 0;
}