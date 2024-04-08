#include <bits/stdc++.h>

using namespace std;

// Creating a comparison function
bool cmp( const int a, const int b ){
    return a > b;
}

void printVector( const vector<int> vect ){
    for( auto element : vect )
        cout << element << ' ';
    cout << endl;
}

int main(){
    vector<int> vect = {1, 4, 2, 7, 1, 3, 5};
    printVector(vect);
    sort( vect.begin(), vect.end(), cmp );
    printVector(vect);

    return 0;
}