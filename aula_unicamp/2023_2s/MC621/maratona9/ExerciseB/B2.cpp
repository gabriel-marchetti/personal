#include <bits/stdc++.h>

using namespace std;

bool is_cat( string s )
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i{0};
    int n_m{0}, n_e{0}, n_o{0}, n_w{0};

    while( s[i] == 'm' ){
        i++;
        n_m++;
    }
    while( s[i] == 'e' ){
        i++;
        n_e++;
    }
    while( s[i] == 'o' ){
        i++;
        n_o++;
    }
    while( s[i] == 'w' ){
        i++;
        n_w++;
    }
    
    if( i == s.size()  && n_m > 0 && n_e > 0 && n_o > 0 && n_w > 0 ) return true;
    else return false;
}

int main(void)
{
    string s;
    long t, n;
    cin >> t;
    while(t--){
        cin >> n >> s;
        if( is_cat(s) ){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}