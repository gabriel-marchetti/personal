#include <bits/stdc++.h>
#define INF 10000000
#define V 100 // num of vertices
using namespace std;

vector<int> dist(V, INF);
vector<int> pred(V, -1);

int main(){
    int s; // source
    dist[s] = 0;
    
    for( int i{0}; i <= V - 1; ++i ){
        for( int u{0}; u < V; ++u ){
            for( int j{0}; j < (int) adjList[u].size(); ++j ){
                pair<int, int> v = adjList[u][j];
                if( dist[u] + v.second < dist[v.first] ){
                    dist[v.first] = dist[u] + v.second;
                    pred[v.first] = u;
                }
            }
        }
    }

}