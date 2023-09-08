#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int t{0};
    long long path{0}, treeSize{0};

    cin >> t;
    for(int i{0}; i < t; i++){
        path = 0;
        cin >> treeSize;
        while( treeSize != 1 ){
            path += treeSize;
            treeSize = treeSize / 2;
        }
        path += treeSize; // treeSize is one.

        cout << path << '\n';
    }

    return 0;
}