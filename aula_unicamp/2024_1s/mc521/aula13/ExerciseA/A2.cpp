#include <bits/stdc++.h>
#define MAX_SIZE 800

using namespace std;

double adj_matrix[MAX_SIZE][MAX_SIZE];
vector<bool> taken;
vector<double> min_edge;
priority_queue<pair<double, int>> pq;

double euclidian_distance( pair<double, double> p1, pair<double, double> p2 ){
    double dx = (p1.first - p2.first),
           dy = (p1.second - p2.second);
    return sqrt( dx*dx + dy*dy );
}

void clearMatrix( double (&adj_matrix)[MAX_SIZE][MAX_SIZE], int num_islands ){
    for(int i = 0; i < num_islands; ++i ){
        for( int j = 0; j < num_islands; ++j ){
            adj_matrix[i][j] = 0.0;
        }
    }
}

double primMST( int num_islands ){
    taken.assign(num_islands, false);
    min_edge.assign(num_islands, DBL_MAX);
    double min_cost = 0.0;
    pq.push({0.0, 0});
    min_edge[0] = 0.0;

    while( !pq.empty() ){
        auto [weight, u] = pq.top();
        pq.pop();

        if( taken[u] ) continue;

        taken[u] = true;
        min_cost += weight;

        for( int v = 0; v < num_islands; ++v ){
            if( v == u ) continue;
            if( !taken[v] && adj_matrix[u][v] < min_edge[v] ){
                min_edge[v] = adj_matrix[u][v];
                pq.push({-adj_matrix[u][v], v});
            }
        }

    }

    return min_cost;
}

int main(){
    int test_cases;
    cin >> test_cases;

    vector<pair<double, double>> points_read;
    while(test_cases--){
        int num_islands;
        cin >> num_islands;
        points_read.clear();
        clearMatrix( adj_matrix, num_islands );
        double x_coord, y_coord;
        for( int i = 0; i < num_islands; ++i ){
            cin >> x_coord >> y_coord;
            points_read.push_back(pair<double, double>(x_coord, y_coord));
        }

        // Compute distances;
        for( int i = 0; i < (int) points_read.size(); ++i ){
            for( int j = i; j < (int) points_read.size();  ++j ){
                pair<double, double> p1 = points_read[i],
                                     p2 = points_read[j];
                double dist = euclidian_distance(p1, p2);
                adj_matrix[i][j] = dist;
                adj_matrix[j][i] = dist;
            }
        }

        // Already with distance between islands.
        printf("%f\n", -primMST(num_islands));

    }

    return 0;
}