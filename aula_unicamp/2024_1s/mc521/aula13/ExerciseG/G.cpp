#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> reach;
    reach.reserve(n);
    reach.assign(n, 0);

    int jump_size;
    reach[0] = 1;
    for( int i = 0; i < n - 1; ++i ){
        cin >> jump_size;
        if( reach[i] == 1 )
            reach[i+jump_size] = 1;
    }

    if( reach[t-1] ){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    // for( auto &elem : reach ){
    //     printf("%d ", elem);
    // } printf("\n");

    return 0;
}