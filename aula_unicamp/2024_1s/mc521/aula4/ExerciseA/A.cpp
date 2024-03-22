#include <bits/stdc++.h>

bool checkCherries( int A, int B, const std::vector<std::pair<int, int>> v ){
    int upward{0}, downward{0}, discriminant{0};
    for( int k{0}; k < v.size(); k++ ){
        discriminant = A * v[k].first + B * v[k].second;
        if( discriminant > 0 )
            upward++;
        else if( discriminant < 0 )
            downward++;
    }
    return ( upward == downward );
}

int main(){
    int n, x, y;
    std::vector<std::pair<int,int>> cherries;
    bool existSolution;
    while( scanf("%d", &n), n ){
        cherries.clear();
        existSolution = false;
        for(int i{0}; i < 2*n; i++){
            scanf("%d %d", &x, &y);
            cherries.push_back( std::make_pair(x, y) );
        }

        for(int A{0}; A <= 500; A++){
            for(int B{-500}; B <= 500; B++){
                if( checkCherries(A, B, cherries) ){
                    printf("%d %d\n", A, B);
                    existSolution = true;
                    break;
                }
            }

            if( existSolution ) break;
        }
    }

    return 0;
}