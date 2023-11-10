#include <bits/stdc++.h>

using namespace std;

struct point{
    double x, y;
};

double euclidian_norm(point p1, point p2){
    double aux = ( p1.x - p2.x )*( p1.x - p2.x ) + ( p1.y - p2.y )*( p1.y - p2.y );
    return sqrt(aux);
}

int main(void){
    int position, count{0};
    point array[9];
    for(int i{0}; i < 3; i++){
        for( int j{0}; j < 3; j++){
            cin >> position;
            position--;
            array[position].x = i;
            array[position].y = j;
        }
    }

    double length{0};
    for(int i{0}; i < 8; i++){
        length += euclidian_norm( array[i], array[i + 1] );
    }

    cout << setprecision(10) << length << endl;
    return 0;
}