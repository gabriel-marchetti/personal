#include <bits/stdc++.h>

int main(){
    int N, division, remainder;
    bool existSol = false;
    std::cin >> N;
    while( N != 0 ){
        existSol = false;
        for( int i{2}; i <= 99999; i++ ){
            for( int j{1}; j <= i/2; j++ ){
                division = i / j;
                remainder = i % j;
                if( (division == N) && (remainder == 0) ){
                    existSol = true;
                    printf("%d / %d = %d\n", i, j, N);
                }
            }
        }

        if( !existSol )
            printf("There are no solution for %d.\n", N);
        std::cin >> N;
    }

    return 0;
}