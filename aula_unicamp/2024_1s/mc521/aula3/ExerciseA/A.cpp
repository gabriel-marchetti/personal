#include <bits/stdc++.h>
#define MAX 5010

using namespace std;

vector<vector<int>> adjList(MAX);
int visited[MAX]{0};
int n;
bool isTriangle = false;

void dfs( int node, int depth ){
    if( visited[node] ) return; 
    visited[node] = 1;
    depth++;
    int willVisit{0};
    for( vector<int>::iterator it = adjList[node].begin(); 
         it != adjList[node].end(); it++ )
    {
        willVisit = *it;
        if(depth < 3)
            dfs(willVisit, depth);
        //printf("%d\n", willVisit);
        if( depth == 3 && visited[willVisit] ){
            isTriangle = true;
            return;
        }
    }
    visited[node] = 0;
}

int main(){
    cin >> n;

    int reader;
    for( int i{0}; i < n; i++){
        cin >> reader;
        reader--; // adjust for vector index
        adjList[i].push_back(reader);
    }

    for(int i{0}; i < n; i++){
        dfs(0, 0);
    }

    if( isTriangle )
        cout << "YES\n";
    else 
        cout << "NO\n";

    return 0;
}