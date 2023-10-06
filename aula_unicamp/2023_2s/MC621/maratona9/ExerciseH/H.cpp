#include <bits/stdc++.h>

using namespace std;

bool search( string s )
{
    string lowercase_s = s;
    transform(lowercase_s.begin(), lowercase_s.end(), lowercase_s.begin(), ::tolower);
    // cout << lowercase_s << endl;
    for( int i{0}; i <= ( s.size() - 3 ); i++ ){
        if( lowercase_s[i] == 'f' && lowercase_s[i+1] == 'b' && lowercase_s[i+2] == 'i' ) 
                return true;
    }
    
    return false;
}

int main(void)
{
    string s;
    int array[5]{0};
    for(int i{0}; i < 5; i++){
        cin >> s;
        if( search(s) ) array[i] = 1;
    }

    int flag = 1;
    for(int i{0}; i < 5; i++){
        if( array[i] == 1 ){
            cout << i + 1 << ' ';
            flag = 0;
        }
    }

    if(flag) cout << "HE GOT AWAY!";
    cout << endl;

    return 0;
}