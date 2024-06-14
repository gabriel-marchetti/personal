#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
};

struct Distance{
    double distance;
    pair<int, int> pair_connected;
};

double euclidian_distance( Point p1, Point p2 ){
    double dx = p1.x - p2.x,
           dy = p1.y - p2.y;
    return sqrt( dx*dx + dy*dy );
}

void printList(const vector<Distance> vector){
    for( int i{0}; i < vector.size(); ++i ){
        printf("%d %d : %f\n", vector[i].pair_connected.first,
                               vector[i].pair_connected.second,
                               vector[i].distance);
    }
}

bool cmp( Distance d1, Distance d2 ){
    if( d1.distance <= d2.distance )
        return true;
    return false;
}

int main(){
    int case_seen{1};
    while( true ){
        int num_pairs, num_points;
        cin >> num_pairs;
        if( num_pairs == 0 )
            break;
        num_points = 2 * num_pairs;
        vector<Point> points;
        points.resize(num_points);
        string name;
        for( int i{0}; i < num_points; ++i ){
            double x, y;
            cin >> name >> x >> y;
            points[i].x = x;
            points[i].y = y;
        }

        vector<Distance> distances;
        for( int i{0}; i < points.size(); ++i ){
            for( int j{i + 1}; j < points.size(); ++j ){
                Distance d_aux;
                d_aux.distance = euclidian_distance(points[i], points[j]);
                d_aux.pair_connected = pair<int, int>(i, j);
                distances.push_back(d_aux);
            }
        }

        sort(distances.begin(), distances.end(), cmp);
        printList(distances);
        vector<bool> already_taken;
        int pairs_made{0};
        double min_cost{0};
        already_taken.reserve(num_points);
        already_taken.assign(num_points, false);
        for( int i{0}; i < distances.size(); ++i ){
            if( pairs_made == num_pairs ) break;
            if( already_taken[distances[i].pair_connected.first] ||
                already_taken[distances[i].pair_connected.second] ) continue;
            min_cost += distances[i].distance;
            already_taken[distances[i].pair_connected.first] = true;
            already_taken[distances[i].pair_connected.second] = true;
        }
        
        printf("Case %d: %.2f\n", case_seen, min_cost);
        case_seen++;
    }

    return 0;
}