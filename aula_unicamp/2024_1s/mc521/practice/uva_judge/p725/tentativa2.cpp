#include <bits/stdc++.h>

int main(){
    int N;
    bool existSol = false;
    std::bitset<10> alreadyUsed, mustBe;
    mustBe.set();

    std::cin >> N;
    while( N != 0 ){
        existSol = false;

        int j_copy, i_copy, aux;
        for(int j{01234}; j <= 98765 / N; j++){
            alreadyUsed.reset();
            j_copy = j;
            i_copy = N * j_copy;
            while( i_copy ){
                aux = i_copy % 10;
                i_copy = i_copy / 10;
                alreadyUsed.set(aux);
            }

            while( j_copy ){
                aux = j_copy % 10;
                j_copy = j_copy / 10;
                alreadyUsed.set(aux);
            }

            if( alreadyUsed == mustBe ){
                existSol = true;
                printf("%d / %d = %d\n", j * N, j, N);
            }
        }

        if( !existSol )
            printf("There are no solution for %d.\n", N);
        std::cin >> N;
    }

    return 0;
}