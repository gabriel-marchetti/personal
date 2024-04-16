#include <bits/stdc++.h>
using namespace std;


int main(){
    string s = "zzzeebbraaa";
    map<char, int> mp;
    for( int i{0}; i < s.size(); ++i ){
        mp[s[i]]++;
    }

    auto str_cmp = [&]( char a, char b ){
        if( mp[a] != mp[b] ){
            return mp[a] > mp[b];
        }
        else{
            return a > b;
        }
    }; 
    cout << s << endl;
    sort( s.begin(), s.end(), str_cmp );
    cout << s << endl;

    return 0;
}