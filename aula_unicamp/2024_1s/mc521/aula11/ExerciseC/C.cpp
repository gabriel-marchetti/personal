#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

vector<vector<pair<int, int>>> adjList;

bool hasNegCycle_solve( int source, int nodes ){
    vector<int> dist(nodes, INF);
    dist[source] = 0;

    // Relax all possible.
    for( int i = 0; i < nodes - 1; i++ ){
        bool modified = false;
        for( int u = 0; u < nodes; u++ ){
            if( dist[u] != INF ){
                for( auto &elem : adjList[u] ){
                    int node = elem.first;
                    int weight = elem.second;

                    if( dist[u] + weight >= dist[node] ) continue;
                    dist[node] = dist[u] + weight;
                    modified = true;

                }
            }
        }
        if( !modified ) break;
    }
    
    // Check if we can minimize. If so, we have infty cycles.
    bool hasNegCycle = false;
    for( int u = 0; u < nodes; ++u ){
        if( dist[u] != INF ){
            for( auto &elem : adjList[u] ){
                int v = elem.first;
                int w = elem.second;
                if( dist[v] > dist[u] + w ){
                    hasNegCycle = true;
                }
            }
        }
    }

    return hasNegCycle;
}

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        int nodes, edges;
        cin >> nodes >> edges;
        adjList.clear();
        adjList.resize(nodes);
        for( int edges_i{0}; edges_i < edges; ++edges_i ){
            int tmp_x, tmp_y, tmp_weight;
            cin >> tmp_x >> tmp_y >> tmp_weight;
            adjList[tmp_x].push_back( {tmp_y, tmp_weight} );
        }

        if( hasNegCycle_solve(0, nodes) ){
            cout << "possible" << '\n';
        }
        else{
            cout << "not possible" << '\n';
        }
        

    }

    return 0;
}