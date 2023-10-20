#include <bits/stdc++.h>

using namespace std;

int main(){
    string input1, input2;
    int next, lcs{0};
    int p, k;
    while( getline(cin, input1) && getline(cin, input2) ){
        int n = p = input1.size(), m = k = input2.size(); // n: lines and m: columns
        int matrix[1001][1001];
        matrix[0][0] = 0;
        lcs = 0;
        for(int i{1}; i <= n; i++) matrix[i][0] = 0;
        for(int j{1}; j <= m; j++) matrix[0][j] = 0;

        for(int i{1}; i <= n; i++){
            for(int j{1}; j <= m; j++){
                next = max( matrix[i-1][j], matrix[i][j-1] );
                if( input1[i-1] == input2[j-1] ){
                    matrix[i][j] = matrix[i-1][j-1] + 1;
                } else{
                    matrix[i][j] = next;
                }
                if( matrix[i][j] > lcs ) lcs = matrix[i][j];
            }
        }
        cout << lcs << endl;
    }
    return 0;
}