#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, index, abc[26]{0};
    string s;
    cin >> n >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for( int i = 0; i < s.size(); i++ ){
        // Use of ASCII pattern.
        index = s[i] - 97;
        abc[index]++;
    }
    for(int i = 0; i < 26; i++ ){
        if( abc[i] == 0 ){
            printf("NO\n");
            return 0;
        }  
    }
    printf("YES\n");
    return 0;
}