#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ii;
typedef vector<long long> vi;
typedef vector<ii> vii;

vector<vii> AL;                                  // the graph stored in AL
vi taken;                                        // to avoid cycle
priority_queue<ii> pq;                           // to select shorter edges
// C++ STL priority_queue is a max heap, we use -ve sign to reverse order

void process(long long u) { // set u as taken and enqueue neighbors of u
    taken[u] = 1;
    for (auto &[v, w] : AL[u])
        if (!taken[v])
            pq.push({-w, -v});                         // sort by non-dec weight
}              

int main(){
    long long roads, junctions;
    while(true){
        cin >> junctions >> roads;
        if( junctions == 0 && roads == 0)
            break;

        AL.assign(junctions, vii());
        pq = priority_queue<ii>();
        long long total_light = 0;
        for( long long i = 0; i < roads; ++i ){
            long long u, v, w;
            cin >> u >> v >> w;
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);
            total_light += w;
        }
        taken.assign(junctions, 0);
        process(0);
        long long mst_cost = 0, num_taken = 0;
        while( !pq.empty() ){
            auto [w, u] = pq.top();
            pq.pop();
            // Since pq have negative number, we need to convert
            w = -w; u = -u;
            if( taken[u] ) continue;

            mst_cost += w;
            process(u);
            ++num_taken;
            if( num_taken == junctions - 1 ) break;
        }
        printf("%lld\n", total_light - mst_cost);
    }
}