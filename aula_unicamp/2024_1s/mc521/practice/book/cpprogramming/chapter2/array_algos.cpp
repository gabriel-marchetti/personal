#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int id;
    int solved;
    int penalty;
} team;

bool icpc_cmp( team a, team b ){
    if( a.solved != b.solved ){
        return a.solved > b.solved;
    }
    else if( a.penalty != b.penalty ){
        return a.penalty < b.penalty;
    }
    else{
        return a.id < b.id;
    }
}

int main(){
    int arr[] = {10, 7, 2, 15, 4};
    vector<int> v(arr, arr+5);

    // Sorting in descending order;
    sort( v.rbegin(), v.rend() );
    // using the (auto &val : v) use reference iteration, that means that 
    // changing val will change the value of the original container
    // NOTE: Using ( auto val : v ) will use a copy of the element
    for( auto &val : v )
        printf("%d ", val);
    printf("\n");
    printf("==========================\n");

    return 0;
}