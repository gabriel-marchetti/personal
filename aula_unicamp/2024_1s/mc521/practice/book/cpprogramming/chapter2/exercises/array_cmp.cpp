#include <bits/stdc++.h>
using namespace std;

bool ascending_cmp( int a, int b ){
    return a < b;
}

int main(){
    vector<int> v = {7, 1, 3, 4, 6, 8, 3};
    for( auto &elem : v )
        printf("%d ", elem);
    printf("\n");
    // lambda function for descending order
    auto descending_cmp = [&]( int a, int b ){ return a > b; };
    sort( v.begin(), v.end(), ascending_cmp );
    for( auto &elem : v )
        printf("%d ", elem);
    printf("\n");
    sort( v.begin(), v.end(), descending_cmp );
    for( auto &elem : v )
        printf("%d ", elem);
    printf("\n");
    
    return 0;
}