#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;

bool search( string s )
{
    string lowercase_s = s;
    transform(lowercase_s.begin(), lowercase_s.end(), lowercase_s.begin(), ::tolower);
    // cout << lowercase_s << endl;
    for( int i{0}; i <= ( s.size() - 7 ); i++ ){
        if( lowercase_s[i] == 'p' && lowercase_s[i+1] == 'r' && lowercase_s[i+2] == 'o' && lowercase_s[i+3] == 'b' 
            && lowercase_s[i+4] == 'l' && lowercase_s[i+5] == 'e' && lowercase_s[i+6] == 'm' ) 
                return true;
    }
    
    return false;
}

int main(void)
{
    string s;
    while( getline(cin, s) ){
        // cout << s << endl;
        if( s.size() >= 7 && search(s) ) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}