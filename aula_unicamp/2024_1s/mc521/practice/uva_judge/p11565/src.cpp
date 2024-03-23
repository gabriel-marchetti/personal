#include <bits/stdc++.h>

int main(){
    int N;
    long long A, B, C;
    bool solvable;
    scanf("%d", &N);
    while( N-- ){
        solvable = false;
        scanf("%d %d %d", &A, &B, &C);
        for( int x{-22}; x <= 22 && !solvable; x++ ){
            if( x != 0 && x * x <= C ){
                if( x > 0 ){
                    for( int y{0}; y < 100 && !solvable; y++){
                        if( (x != y) && ( x * x + y * y <= C ) ){
                            for( int z{0}; z < 100 && !solvable; z++){
                                if( (z != x) && (z != y) &&
                                    (x + y + z == A) &&
                                    (x * y * z == B) &&
                                    (x*x + y*y + z*z == C)
                                    ){
                                        printf("%d %d %d\n", x, y, z);
                                        solvable = true;
                                }
                            }
                        }
                    }
                }else{
                    for( int y{-100}; y < 0 && !solvable; y++){
                        if( (x != y) && ( x * x + y * y <= C ) ){
                            for( int z{0}; z < 100 && !solvable; z++){
                                if( (z != x) && (z != y) &&
                                    (x + y + z == A) &&
                                    (x * y * z == B) &&
                                    (x*x + y*y + z*z == C)
                                    ){
                                        printf("%d %d %d\n", x, y, z);
                                        solvable = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        if( !solvable ) printf("No solution.\n");

    }

    return 0;
}