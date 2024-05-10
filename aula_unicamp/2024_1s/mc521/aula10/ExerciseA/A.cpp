#include <bits/stdc++.h>
#define MAX_N 1010
#define VISITED 1
#define UNVISITED -1
using namespace std;

int parent[MAX_N];
int visited[MAX_N];

int find( int current, int (&parent)[MAX_N], int (&visited)[MAX_N] ){
    if( visited[current] == VISITED )
        return current;
    visited[current] = VISITED;
    find( parent[current], parent, visited );
    
}

int main(){
    int n;
    cin >> n;
    for( int i{1}; i <= n; ++i ){
        int tmp;
        cin >> tmp;
        parent[i] = tmp;    
    }

    for( int i{1}; i <= n; ++i ){
        memset(visited, UNVISITED, sizeof(visited));
        cout << find(i, parent, visited) << ' ';
    }
    cout << "\n";

    return 0;
}