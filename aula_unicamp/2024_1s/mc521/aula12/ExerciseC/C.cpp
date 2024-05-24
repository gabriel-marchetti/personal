#include <bits/stdc++.h>
#define MAX_NODES 160
#define INF 100000000
#define VISITED 1
#define UNVISITED -1

using namespace std;

void floydWarshall( int (&dist)[MAX_NODES][MAX_NODES], int nodes ){
    for( int k{0}; k < nodes; k++){
        for( int i{0}; i < nodes; i++){
            for( int j{0}; j < nodes; j++){
                if( dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] < INF && dist[k][j] < INF )
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void initializeMatrix( int (&graph)[MAX_NODES][MAX_NODES], int nodes ){
    for( int i{0}; i < nodes; i++ ){
        for( int j{0}; j < nodes; j++ ){
            graph[i][j] = ( i == j ) ? 0 : INF;
        }
    }
}

bool checkNegativeCycle( int u, int v, int nodes, int (&graph)[MAX_NODES][MAX_NODES] ){
    for( int i{0}; i < nodes; i++ ){
        if( graph[i][i] < 0 && graph[u][i] < INF/2 && graph[i][v] < INF/2 ){
            return true;
        } 
    }
    return false;
}

void printMatrix(int nodes, const int (&graph)[MAX_NODES][MAX_NODES]){
    for(int i{0}; i < nodes; i++){
        for( int j{0}; j < nodes; j++ ){
            if( graph[i][j] > INF/2 )
                printf("INF\t");
            else
                printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int nodes, edges, queries;
    int graph[MAX_NODES][MAX_NODES];
    int u, v, w;
    while( true ){
        cin >> nodes >> edges >> queries;
        if( nodes == 0 && edges == 0 && queries == 0 ){
            break;
        }

        initializeMatrix(graph, nodes);
        
        for( int i{0}; i < edges; i++ ){
            cin >> u >> v >> w;
            graph[u][v] = min(w, graph[u][v]);
        }
        floydWarshall(graph, nodes);


        int q_u, q_v;
        // printMatrix(nodes, graph);
        for( int i{0}; i < queries; i++ ){
            cin >> q_u >> q_v;

            if( checkNegativeCycle(q_u, q_v, nodes, graph) ){
                cout << "-Infinity" << '\n';
            }
            else if( graph[q_u][q_v] >= INF ){
                cout << "Impossible" << '\n';
            }
            else{
                cout << graph[q_u][q_v] << "\n";
            }
        }

        cout << '\n';
    }

    return 0;
}