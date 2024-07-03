#include <bits/stdc++.h>
#define MY_RNG std::mt19937

int main(){
    uint32_t seed_val;
    MY_RNG RNG(seed_val);
    
    std::uniform_int_distribution<uint32_t> uint_dist(0, 100);
    std::set<uint32_t> elementsSet;
    int sortTimes;
    scanf("%d", &sortTimes);
    for( int i{0}; i < sortTimes; ++i ){
        elementsSet.insert( uint_dist(RNG) );
    }

    for( auto it = elementsSet.begin(); it != elementsSet.end(); it++ ){
        printf("%u ", *it );
    }
    printf("\n");

    return 0;
}