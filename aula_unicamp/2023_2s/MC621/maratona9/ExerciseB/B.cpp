#include <bits/stdc++.h>

using namespace std;

bool is_cat( string str )
{
    string s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    char accept[] = {'m', 'e', 'o', 'w'};
    bool flagM = false, flagE = false, flagO = false, flagW = false, flag=false;
    for( int i{0}; i < s.size(); i++ ){
        flag = false;
        for(int j{0}; j < 4; j++){
            if( s[i] == accept[j] ){
                flag = true;
                break;
            }
        }
        if( !flag ) return false;
        if( flagM || s[i] == 'm'){
            flagM = true;
        }
        if( flagM && s[i] == 'e' ){
            flagE = true; 
        }
        /* Não pode aparecer o m novamente */
        if( flagE && s[i] == 'm' ) return false;
        if( flagE && s[i] == 'o'){
            flagO = true;
        }
        /* Não pode aparecer o m e o e novamente */
        if( flagO && ( s[i] == 'm' || s[i] == 'o' ) ) return false;
        if( flagO && s[i] == 'w'){
            flagW = true;
        } 
        /* Não pode aparecer o m, o o e o e novamente */
        if( flagW && ( s[i] == 'm' || s[i] == 'e' || s[i] == 'o' ) ) return false;
    }
    if( flagW ) return true;
    
    return false;
}

int main(void)
{
    string s;
    long t, n;
    cin >> t;
    while(t--){
        cin >> n;
        getline(cin, s);
        if( is_cat(s) ){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}