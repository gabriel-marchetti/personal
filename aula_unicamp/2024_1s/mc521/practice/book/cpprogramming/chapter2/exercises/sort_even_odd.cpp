#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // Sorting: Even should appear first than odd's.
    auto compare = [&]( int a, int b ){
        return a % 2 < b % 2;
    };
    
    for( auto &elem : arr ){
        printf("%d ", elem);
    }
    printf("\n");
    sort( arr, arr + 7, compare );
    for( auto &elem : arr ){
        printf("%d ", elem);
    }
    printf("\n");

    return 0;
}