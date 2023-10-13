#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    int a{0}, t{0}, c{0}, g{0};
    int max{0}, aux{0};

    for(int i{0}; i < str.length(); i++){
        if( str[i] == 'A' ){
            a++;
            t = c = g = 0;
            aux = a;
        } else if ( str[i] == 'T' ){
            t++;
            a = c = g = 0;
            aux = t;
        } else if ( str[i] == 'C' ){
            c++;
            a = t = g = 0;
            aux = c;
        } else {
            g++;
            a = t = c = 0;
            aux = g;
        }

        if( aux > max ) max = aux;
    }

    cout << max << endl;

    return 0;
}