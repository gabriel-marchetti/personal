#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

vector<vector<pair<int, int>>> adjList_cor;
vector<vector<pair<int, int>>> adjList_rev;
vector<int> dist_source;
vector<int> dist_end;

void dijkstra( int source, int nodes, vector<int> &dist,  vector<vector<pair<int, int>>> & adjList){
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
    cin >> testcases;

    while(testcases--){
        int nodes, edges, num_possible_two_ways, source, end;
        cin >> nodes >> edges >> num_possible_two_ways >> source >> end;
        adjList_cor.clear();
        adjList_cor.resize(nodes);

        adjList_rev.clear();
        adjList_rev.resize(nodes);
        source--; end--;

        for( int i{0}; i < edges; i++ ){
            int tmp_x, tmp_y, tmp_w;
            cin >> tmp_x >> tmp_y >> tmp_w;
            tmp_x--; tmp_y--;
            adjList_cor[tmp_x].push_back({tmp_y, tmp_w});
            adjList_rev[tmp_y].push_back({tmp_x, tmp_w});
        }

        dist_source.resize(nodes);
        dist_end.resize(nodes);
        
        dijkstra(source, nodes, dist_source, adjList_cor);
        dijkstra(end, nodes, dist_end, adjList_rev);
        
        int smallest_path = INF;
        for( int j{0}; j < num_possible_two_ways; j++ ){
            int x, y, w;
            cin >> x >> y >> w;
            x--; y--;
            
            // cout << "---------\n";
            // cout << dist_source[x] << ' ' << dist_source[y] << '\n';
            // cout << dist_end[x] << ' ' << dist_end[y] << '\n';
            smallest_path = min(smallest_path, dist_source[end]);
            smallest_path = min(smallest_path, w + min(dist_source[x] + dist_end[y], dist_source[y] + dist_end[x]) );
        }
        
        if( smallest_path == INF ){
            cout << -1 << '\n';
        }
        else{
            cout << smallest_path << '\n';
        }
    }

    return 0;
}