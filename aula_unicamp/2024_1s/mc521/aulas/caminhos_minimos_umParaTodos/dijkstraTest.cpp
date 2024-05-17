#include <bits/stdc++.h>
#define TAM 100
using namespace std;

class Graph{
    public:
        int numNodes;
        vector<pair<int, int>> adjList[TAM];

        void addEdge( int u, int v, int w ){
            adjList[u].push_back({v, w});
        }

        void setup(){
            for( int i{0}; i < numNodes; ++i ){
                adjList[i].clear();
            }
        }
};