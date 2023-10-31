#include <bits/stdc++.h>

using namespace std;


int reverse( string str1, string str2 ){
    // 1: é palindromo
    // 0: não palindromo
    int n = str1.size();
    int j = 0, k = n - 1;
    for(int i = 0; i < n - 1; i++ ){
        if( str1[j] != str2[k] )
            return 0;
        j++; k--;
    }
    return 1;
}


int main(){
    int t, n;
    
    cin >> t;
    while( t-- ){
        string str,
               one_preffix{0}, one_suffix{0}, partial_preffix{0}, partial_suffix{0},
               aux;
        int visited1{0}, visited2{0};
        int visited3{0}, visited4{0};
        cin >> n;
        for( int i = 0; i < 2*(n-1); i++ ){
            cin >> aux;
            // cout << aux << endl;
            if( aux.size() == 1 && visited1 == 0 ){
                visited1 = 1;
                one_preffix = aux;
            }
            else if( aux.size() == 1 && visited2 == 0 ){
                visited2 = 1;
                one_suffix = aux;
            }


            if( aux.size() == n - 1 && visited3 == 0 ){
                visited3 = 1;
                partial_preffix = aux;
            }
            else if( aux.size() == n - 1 && visited4 == 0 ){
                visited4 = 1;
                partial_suffix = aux;
            }
            
        }

        // int iter{1};
        // cout << iter << "--------" << endl;
        // iter++;
        // cout << one_preffix << endl;
        // cout << one_suffix << endl;
        // cout << partial_preffix << endl;
        // cout << partial_suffix << endl;
        if( one_preffix != one_suffix )
            cout << "NO" << endl;
        else if( !reverse(partial_preffix, partial_suffix) )
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}