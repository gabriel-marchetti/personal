#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, abc[26]{0}, index, odds{0}, aux{0};
    string s;
    cin >> t;
    while( t-- ){
        for(int i{0}; i < 26; i++) abc[i] = 0;
        odds = 0;
        aux = 0;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            index = s[i] - 97;
            //cout << index << endl;
            abc[index]++;
        }
        for(int i = 0; i < 26; i++){
            odds = odds + ( abc[i] % 2 ) ? 1 : 0;
            if( abc[i] > 1 )
                aux++;
            //cout << abc[i] << ' ';
        }
        //cout << endl;
        
        if( odds <= 1 && aux > 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}