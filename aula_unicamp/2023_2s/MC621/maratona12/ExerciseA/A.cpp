#include <bits/stdc++.h>

using namespace std;
#define RADIUS 8

struct point{
    double x,y; 
};

double euclidian_norm(point p1, point p2){
    double aux = ( p1.x - p2.x )*( p1.x - p2.x ) + ( p1.y - p2.y )*( p1.y - p2.y );
    return sqrt(aux);
}

int main(void){
    int m{0}, num_candles{0};

    cin >> m;
    point book, candle;
    double i_candle_x{0}, i_candle_y{0};
    bool read{0};
    for(int j{0}; j < m; j++){
        read = false;
        cin >> book.x >> book.y;
        cin >> num_candles;
        for(int i{0}; i < num_candles; i++){
            cin >> i_candle_x >> i_candle_y;
            candle.x = i_candle_x; candle.y = i_candle_y;
            if( euclidian_norm( book, candle ) <= RADIUS  && read == false ){
                printf("light a candle\n");
                read = true;
            }
        }
        if( !read ) printf("curse the darkness\n");
    }

    return 0;
}