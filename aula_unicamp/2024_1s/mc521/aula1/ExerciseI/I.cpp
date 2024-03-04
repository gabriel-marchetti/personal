#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    int array[10]{0}, index;
    getline(cin, str);

    for( int i{0}; i < str.size(); i++ ){
        index = (int) str[i] - 48;
        array[index]++;
    }

    if( array[4] != 0 && array[4] >= array[7] ){
        cout << '4' << endl;
    } else if ( array [7] != 0 ){
        cout << '7' << endl;
    } else{
        cout << "-1" << endl;
    }

    /*
    for( int i{0}; i < 10; i++ ){
        cout << array[i] << ' ';
    }
    cout << endl;
    */

    return 0;
}