#include <bits/stdc++.h>
#define MAX_N 1010
#define VISITED 1
#define UNVISITED -1
using namespace std;

int visited[MAX_N];
vector<int> AdjNodes[MAX_N];
int strongComponents;

void clean( vector<int> (&array)[MAX_N] ){
    for(int i{0}; i < MAX_N; ++i)
        AdjNodes[i].clear();
}

void setUnvisited( int arr[MAX_N] ){
    for( int i{0}; i < MAX_N; ++i )
        arr[i] = UNVISITED;
}

void dfs( int node ){
    if( visited[node] == VISITED ) return;
    //cout << node << ' ';
    visited[node] = VISITED;
    for( auto neigh : AdjNodes[node] ){
        dfs( neigh );
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int nodes, edges;
        strongComponents = 0;
        setUnvisited( visited );
        clean( AdjNodes );  
        cin >> nodes >> edges;
        for( int i{0}; i < edges; ++i ){
            int edge1, edge2;
            cin >> edge1 >> edge2;
            AdjNodes[edge1].push_back(edge2);
            AdjNodes[edge2].push_back(edge1);
        }

        for( int i{0}; i < nodes; ++i ){
            if( visited[i] == UNVISITED ) strongComponents++;
            dfs(i);
        }
        //cout << endl;
        cout << strongComponents - 1 << endl;
    }

    return 0;
}