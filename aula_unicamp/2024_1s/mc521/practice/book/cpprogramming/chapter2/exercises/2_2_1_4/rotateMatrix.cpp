#include <bits/stdc++.h>
using namespace std;

int main(){
    int matrix[3][3] ={ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int newMatrix[3][3]{0};
    int j_old = 2;
    for(int i{0}; i < 3; ++i){
        for(int j{0}; j < 3; ++j){
            newMatrix[i][j] = matrix[j][j_old];
        }
        j_old--;
    }
    
    

    for( auto line : newMatrix ){
        for( int j{0}; j < 3; ++j ){
            printf("%d ", line[j] );
        }    
        printf("\n");    
    }
    
}