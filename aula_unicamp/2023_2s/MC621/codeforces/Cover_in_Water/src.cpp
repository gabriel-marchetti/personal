#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t{0}, strSize{0},
        counter{0}, numDots{0};
    bool flag{0};

    cin >> t;
    for(int i{0}; i < t; i++){
        counter = 0;
        numDots = 0;
        flag    = false;
        cin >> strSize;
        char str[strSize];
        cin >> str;
        // cout << str << '\n';
        for(int j{0}; j < strSize; j++){
            if( str[j] == '.' ){
                counter++;
                numDots++;
            } else {
                counter = 0;
            }
            if ( counter == 3 ){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << '2' << '\n';
        } else {
            cout << numDots << '\n';
        }
    }

    return 0;
}