#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "heellloooo";
    map<char, int> mp;

    for( int i{0}; i < s.size(); ++i ){
        mp[s[i]]++;
    }

    auto most_frequent_comparator = [&]( char a, char b ){
        return mp[a] > mp[b];
    };
    cout << s << endl;
    sort( s.begin(), s.end(), most_frequent_comparator );
    cout << s << endl;

    return 0;
}