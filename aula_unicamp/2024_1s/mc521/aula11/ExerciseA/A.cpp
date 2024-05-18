#include <bits/stdc++.h>

using namespace std;
const int INF = INT_MAX / 100;

vector<vector<pair<int, int>>> adjList;
vector<int> dist;

void print_adjList(){
    int node = 0;
    for( const auto &element : adjList ){
        printf("Node %d: ", node++);
        for( const auto &viz : element ){
            printf("(%d, %d) ", viz.first, viz.second);
        }
        printf("\n");
    }
}

void print_dist(){
    for( const auto &elem : dist ){
        printf("%d ", elem);
    }
    printf("\n");
}

void dijkstra( int source, int nodes ){
    dist.assign(nodes, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while( ! pq.empty() ){
        pair<int, int> dist_vertice = pq.top();
        auto __dist = dist_vertice.first;
        auto vertice = dist_vertice.second;
        pq.pop();

        if( __dist > dist[vertice] ) continue;
        //print_dist();
        
        for( const auto &viz : adjList[vertice] ){
            int vizNode = viz.first;
            int weight_vizNode = viz.second;
            if( dist[vizNode] > dist[vertice] + weight_vizNode ){
                dist[vizNode] = dist[vertice] + weight_vizNode;
                pq.push({dist[vizNode], vizNode});
            }
        }

    }
}

int main(){
    int testcases;
    int n_case = 1;
    cin >> testcases;
    while(testcases--){
        int nodes, edges, source, end;
        cin >> nodes >> edges >> source >> end;
        adjList.clear();
        adjList.resize(nodes);
        
        dist.clear();
        dist.resize(nodes);

        for( int edge_i{0}; edge_i < edges; ++edge_i ){
            int tmp_frstNode, tmp_scndNode, tmp_weight;
            cin >> tmp_frstNode >> tmp_scndNode >> tmp_weight;
            adjList[tmp_frstNode].push_back({tmp_scndNode, tmp_weight});
            adjList[tmp_scndNode].push_back({tmp_frstNode, tmp_weight});
        }

        // print_adjList();
        // for( auto &elem : dist ){
        //     printf("%d ", elem);
        // }

        dijkstra(source, nodes);

        printf("Case #%d: ", n_case++);
        
        // printf("\n");
        // printf("Dist: ");
        // for(auto &elem : dist){
        //     printf("%d ", elem);
        // }
        // printf("\n");
        if( dist[end] == INF ){
            printf("unreachable\n");
        }
        else{
            printf("%d\n", dist[end]);
        }

    }

    return 0;
}