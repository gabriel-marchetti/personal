#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long N;
    string s;
    cin >> N;
    cin.ignore();
    while( N-- ){
        getline(cin, s);
        if( s[0] == 'S' && s[1] == 'i' && s[2] == 'm' && s[3] == 'o' && s[4] == 'n' && 
            s[5] == ' ' && s[6] == 's' && s[7] == 'a' && s[8] == 'y' && s[9] == 's'){
                for(int i{10}; i < s.size(); i++) cout << s[i];
                cout << ' ';
                cout << endl;
        }
    }

    return 0;
}