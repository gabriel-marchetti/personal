#include <bits/stdc++.h>

int main(){
    int t{0}, target{0}, numBars{0}, tmp{0}, bars[20]{0};
    bool thereIsSolution{0};
    std::cin >> t;
    
    while(t--){
        thereIsSolution = false;
        std::cin >> target >> numBars;
        for(int i{0}; i < numBars; ++i){
            std::cin >> tmp;
            bars[i] = tmp;
        }

        for( int i{0}; i < (1 << numBars); ++i ){
            int sum = 0;
            for( int j{0}; j < numBars; ++j ){
                if( i & (1 << j) )
                    sum += bars[j];
            }
            if( target == sum ){
                printf("YES\n");
                thereIsSolution = true;
                break;
            }
        }

        if(!thereIsSolution) printf("NO\n");
    }

    return 0;
}