#include <bits/stdc++.h>
#define INF 1000000010
#define TAM 100
using namespace std;


int main(){
    int numVertices;
    int s; // Source
    vector<pair<int, int>> adjList[TAM];

    vector<int> dist(numVertices, INF);
    vector<int> pred(numVertices, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push( pair<int, int>(dist[s], s) );

    while( !pq.empty() ){
        pair<int, int> front = pq.top();
        pq.pop();

        int d = front.first, u = front.second;
        if( d > dist[u] ) continue;

        for( int j = 0; j < (int) adjList[u].size(); ++j ){
            pair<int, int> v = adjList[u][j];
            if( dist[u] + v.second < dist[v.first] ){
                dist[v.first] = dist[u] + v.second;
                pred[v.first] = u;
                pq.push( pair<int, int>( dist[v.first], v.first ) );
            }
        }
    }

    return 0;
}