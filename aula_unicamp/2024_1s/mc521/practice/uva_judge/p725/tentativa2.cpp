#include <bits/stdc++.h>

int main(){
    int N;
    bool existSol = false;
    std::bitset<10> alreadyUsed, mustBe;
    mustBe.set();

    std::cin >> N;
    while( N != 0 ){
        existSol = false;
        alreadyUsed.reset();

        if( !existSol )
            printf("There are no solution for %d.\n", N);
        std::cin >> N;
    }

    return 0;
}