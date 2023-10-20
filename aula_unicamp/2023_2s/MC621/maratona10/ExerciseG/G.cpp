#include <bits/stdc++.h>

using namespace std;

int is_square( string s ){
    int size = s.size();
    
    if( size % 2 )
        return 0;
    
    int i = 0, j = size / 2;
    while( i < size / 2 && j < size ){
        if( s[i] != s[j] )
            return 0;
        i++, j++;
    }

    return 1;
}

int main(){
    int t;
    string s;
    cin >> t;
    while( t-- ){
        cin >> s;
        if( is_square(s) ){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
    }

    return 0;
}