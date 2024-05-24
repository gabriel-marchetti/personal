#include <bits/stdc++.h>
#define MAX 110
#define VISITED 1
#define UNVISITED -1

using namespace std;

void clearPos( pair<int, int> (&distances)[MAX] ){
    for( int i{0}; i < MAX; i++ ){
        distances[i].first = 0;
        distances[i].second = 0;
    }
}

void clearMatrix( int (&matrix)[MAX][MAX] ){
    for(int i{0}; i < MAX; i++){
        for( int j{0}; j < MAX; j++ ){
            matrix[i][j] = 0;
        }
    }
}

int manhattanDistance( pair<int, int> p1, pair<int, int> p2 ){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void dfs( int u, int nodes, vector<int> &visited, const int (&graph)[MAX][MAX] ){
    visited[u] = VISITED;
    for( int v{0}; v < nodes; v++ ){
        if( v == u ) continue;
        if( graph[u][v] && visited[v] == UNVISITED )
            dfs( v, nodes, visited, graph );
    }
}

bool canReach( const int (&graph)[MAX][MAX], int nodes, int source, int destination ){
    vector<int> visited;
    visited.assign(nodes, UNVISITED);
    dfs(source, nodes, visited, graph);
    
    return ( visited[destination] == VISITED ) ? true : false;
}

int main(){
    int testcases;
    cin >> testcases;
    
    int stores;
    pair<int, int> positions[MAX];
    int adjMatrix[MAX][MAX];

    while(testcases--){
        clearPos(positions);
        clearMatrix(adjMatrix);

        cin >> stores;
        int x_pos, y_pos;
        for( int i{0}; i < stores + 2; i++){
            cin >> x_pos >> y_pos;
            positions[i] = pair<int, int>( x_pos, y_pos );
        }

        // if distance is less than 1000 than its a suitable road.
        for( int i{0}; i < stores + 2; i++){
            for( int j{0}; j < stores + 2; j++ ){
                if( manhattanDistance(positions[i], positions[j]) <= 1000 ){
                    adjMatrix[i][j] = 1;
                    adjMatrix[j][i] = 1;
                }
                else{
                    adjMatrix[i][j] = 0;
                    adjMatrix[j][i] = 0;
                }
            }
        }

        if( canReach(adjMatrix, stores + 2, 0, stores + 1) ){
            printf("happy\n");
        }
        else{
            printf("sad\n");
        }

    }

    return 0;
}