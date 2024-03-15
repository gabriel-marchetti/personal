co#include <bits/stdc++.h>
#define MAX 100

/*
 * What you will find here:
 * - adjacence matrix
 * - adjacence list
 * - edge list
 */

using namespace std;
int main(){
    int verticesAdjMatrix;
    cin >> verticesAdjMatrix;
    int adjMatrix[MAX][MAX];

    /*
     * Reading Adjacent Matrix. 
     */
    for(int i{0}; i < verticesAdjMatrix; i++){
        for(int j{0}; j < verticesAdjMatrix; j++)
            scanf("%d", &adjMatrix[i][j]);
    }

    /*
     * Printing Neighbors of Vertex 0.
     */
    printf("Neighbors of Vertex 0:\n");
    for(int j{0}; j < verticesAdjMatrix; j++){
        if( adjMatrix[0][j] )
            printf("Edge 0-%d (weight = %d)\n", j, adjMatrix[0][j]);
    }

    printf("--------------------------\n");

    vector<vector<pair<int,int>>> adjList; 
    int V;
    scanf("%d", &V);

    adjList.assign(V, vector<pair<int,int>>() );
    int totalNeighbors, id, weight;
    for(int i{0}; i < V; i++){
        scanf("%d", &totalNeighbors);
        for(int j{0}; j < totalNeighbors; j++){
            scanf("%d %d", &id, &weight);
            adjList[i].push_back(pair<int,int>(id-1, weight));
        }
    }

    printf("Neighbors of Vertex 0:\n");
    for( vector<pair<int,int>>::iterator it = adjList[0].begin();
    it != adjList[0].end(); it++){
        printf("Edge 0-%d (weight = %d)\n", it->first, it->second);
    }

    printf("--------------------------\n");
    int E, a, b;
    priority_queue<pair<int,pair<int,int>>> edgeList;
    scanf("%d", &E);
    for(int i{0}; i < E; i++){
        scanf("%d %d %d", &a, &b, &weight);
        edgeList.push(make_pair(weight, pair<int,int>(a, b)));
    }

    for(int i{0}; i < E; i++){
        pair<int, pair<int,int>> edge = edgeList.top();
        edgeList.pop();
        printf("weigth = %d for edge %d-%d\n", edge.first, edge.second.first, edge.second.second);
    }


    return 0;
}
