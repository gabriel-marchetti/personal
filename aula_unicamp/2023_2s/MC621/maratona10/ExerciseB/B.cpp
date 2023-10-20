#include <bits/stdc++.h>

using namespace std;

int in_commom(string s, string t){
    int sabc[26]{0}, tabc[26]{0};
    int size = s.size();
    for(int i{0}; i < size; i++){
        int index1 = s[i] - 97, index2 = t[i] - 97;
        sabc[index1]++;
        tabc[index2]++; 
    }

    // for( int i{0}; i < 26; i++ )
    //     cout << sabc[i] << ' ';
    // cout << endl;
    // for( int i{0}; i < 26; i++ )
    //     cout << tabc[i] << ' ';
    // cout << endl;

    


    for( int i{0}; i < 26; i++ ){
        if( sabc[i] > 0 && tabc[i] > 0 )
            return 1;
    }

    return 0;
}

int main(){
    int q;
    string s, t;
    cin >> q;
    while( q-- ){
        cin >> s;
        cin >> t;
        if( in_commom(s, t) ){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
    }
}