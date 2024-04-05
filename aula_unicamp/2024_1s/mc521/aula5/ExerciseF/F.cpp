#include <bits/stdc++.h>
#define MAX 200010

using namespace std;

int computeWaterNeeded( int h, int n, int *heights ){
    int numOfWater{0};
    for(int i{0}; i < n; i++){
        int currentCol = h - heights[i];
        if( currentCol > 0 )
            numOfWater = numOfWater + currentCol;
    }
    return numOfWater;
}

int computeMaxHeight( int x, int n, int *heights ){
    int h = 0;
    while( computeWaterNeeded(h, n, heights) <= x )
        h++;
    h--;
    return h;
}   

int computeMaxHeight_divideConquer( int x, int n, int *heigths ){
    int max_sol = 2000000000, min_sol = 1, solution{0};
    while( true ){
        if( max_sol - min_sol <= 1 ) break;
        //cout << "Min sol: " << min_sol << '\n';
        //cout << "Max sol: " << max_sol << '\n';
        solution = (int) floor( (max_sol + min_sol) / 2 );
        if( computeWaterNeeded(solution, n, heigths) < x ){
            min_sol = solution;
        }
        else{
            max_sol = solution;
        }
    }

    return solution;
}

int main(){
    int t, n, x;
    int heigths[MAX];
    cin >> t;
    while( t-- ){
        cin >> n >> x;
        for(int i{0}; i < n; i++){
            int read; cin >> read;
            heigths[i] = read;
        }

        cout << computeMaxHeight_divideConquer(x, n, heigths) << '\n';
    }

    return 0;
}