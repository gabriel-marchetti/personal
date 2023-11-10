#include <bits/stdc++.h>

using namespace std;

struct point{
    long long x, y;
};

int main(void){
    int t{1};
    long long x, y, divisor_x, divisor_y,
              score_stan{0}, score_ollie{0};
    while( true ){
        cin >> t;
        if( t == 0 ) break;
        score_stan = 0;
        score_ollie = 0;
        point points[t];
        for(int i{0}; i < t; i++ ){
            cin >> x >> y;
            points[i].x = x; points[i].y = y;
        }
        
        divisor_x = points[t/2].x; divisor_y = points[t/2].y;
        //cout << divisor_x << " " << divisor_y << endl;

        for(int i{0}; i < t; i++){
            if( points[i].x == divisor_x || points[i].y == divisor_y ){
                continue;
            } else if ( ((points[i].x > divisor_x) && (points[i].y > divisor_y)) ||
                        ((points[i].x < divisor_x) && (points[i].y < divisor_y)) 
            ){
                score_stan++;      
            } else{
                score_ollie++;
            }
        }

        cout << score_stan << ' ' << score_ollie << endl; 
    }

    return 0;
}