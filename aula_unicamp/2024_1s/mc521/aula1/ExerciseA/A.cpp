#include <bits/stdc++.h>

using namespace std;

int main( ){
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    transform( str1.begin(), str1.end(), str1.begin(), ::tolower );
    transform( str2.begin(), str2.end(), str2.begin(), ::tolower );

    int flag{0};
    for( int i{0}; i < str1.size(); i++ ){
        if( str1[i] < str2[i] ){
            flag = -1;
            break;
        }
        if( str2[i] < str1[i] ){
            flag = 1;
            break;
        }
    }

    cout << flag << endl;

    return 0;
}