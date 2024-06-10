#include <bits/stdc++.h>
#define MAX_SIZE 800

using namespace std;

double adjMatrix[MAX_SIZE][MAX_SIZE];
vector<bool> taken;
priority_queue<pair<int, int>> pq;

double euclidian_distance( pair<double, double> p1, pair<double, double> p2 ){
    double dx = (p1.first - p2.first),
           dy = (p1.second - p2.second);
    return sqrt( dx*dx + dy*dy );
}

void clearMatrix( double (&adjMatrix)[MAX_SIZE][MAX_SIZE], int num_islands ){
    for(int i = 0; i < num_islands; ++i ){
        for( int j = 0; j < num_islands; ++j ){
            adjMatrix[i][j] = 0.0;
        }
    }
}

/**
 * This was taken from GeeksForGeeks
*/
bool isValidEdge(int u, int v){
    if( u == v ){
        return false;
    }
    if( taken[u] == false && taken[v] == false ){
        return false;
    }
    else if( taken[u] == true && taken[v] == true ){
        return false;
    }
    return true;
}

double primMST( int num_islands ){
    taken.assign(num_islands, false);
    taken[0] = true;
    int edges_count = 0;
    double min_cost = 0.0;

    while( edges_count < num_islands - 1 ){
        double min = DBL_MAX;
        int a = -1, b = -1;
        
        for( int i = 0; i < num_islands; ++i ){
            for( int j = 0; j < num_islands; ++j ){
                if( adjMatrix[i][j] < min && isValidEdge(i, j) ){
                    min = adjMatrix[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if( a != -1 && b != -1){
            min_cost += min;
            taken[a] = taken[b] = true;
            edges_count++;
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
        clearMatrix( adjMatrix, num_islands );
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
                adjMatrix[i][j] = dist;
                adjMatrix[j][i] = dist;
            }
        }

        // Already with distance between islands.
        printf("%f\n", primMST(num_islands));

    }

    return 0;
}