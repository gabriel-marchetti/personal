#include <bits/stdc++.h>

using namespace std;

void printVector( vector<int> vect ){
    for( auto element : vect )
        printf("%d ", element);
    printf("\n");
}

int main(){
    vector<int> v(5, 10);
    printVector(v);

    iota(v.begin(), v.end(), 20);
    printVector(v);

    return 0;
}