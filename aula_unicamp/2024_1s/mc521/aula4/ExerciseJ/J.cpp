#include <bits/stdc++.h>

bool equation_A( int x, int y, int z, int A ){
    return ( ( x + y + z ) == A );
}

bool equation_B( int x, int y, int z, int B ){
    return ( ( x*y*z ) == B );
}

bool equation_C( int x, int y, int z, int C ){
    return ( (x*x + y*y + z*z ) == C );
}

int main(){
    int N, A, B, C;
    bool noSolution;

    std::cin >> N;
    while(N--){
        noSolution = true;
        std::cin >> A >> B >> C;
        for(int x{-22}; x < 23; x++){
            for(int y{x+1}; y < 101; y++){
                for(int z{y+1}; z < 101; z++){
                    if( equation_A(x, y, z, A) &&
                        equation_B(x, y, z, B) &&
                        equation_C(x, y, z, C) 
                    ){
                        noSolution = false;
                        printf("%d %d %d\n", x, y, z);
                        break;
                    }
                }
                if( !noSolution ) break;
            }
            if( !noSolution ) break;
        }
        if( noSolution )
            printf("No solution.\n");
    }

    return 0;
}