#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    string str;
    getline(cin, str);

    int numZeros{0}, numOnes{0};
    for( int i{0}; i < str.size(); i++ ){
        if( str[i] == 'z' )
            numZeros++;
        if( str[i] == 'n' )
            numOnes++;
    }

    for( int i{0}; i < numOnes; i++ )
        cout << "1 ";
    for( int i{0}; i < numZeros; i++ )
        cout << "0 ";
    cout << endl; 

    return 0;
}