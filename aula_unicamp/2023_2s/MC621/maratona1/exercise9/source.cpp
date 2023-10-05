#include <bits/stdc++.h>

int main(void)
{
    int t, n, m;
    for(int i{0}; i < t; i++){
        std::cin >> n;
        int alice[n];
        for(int j{0}; j < n; j++)
            std::cin >> alice[j];
        std::cin >> m;
        int bob[m];
        for(int j{0}; j < m; j++)
            std::cin >> bob[j];
        
        int flag = 1;
        int maxA, maxB;
        int indexA, indexB;
        char winner;
        while( flag ){
            // Identify max card of Alice.
            for( int j{0}; j < n; j++ ){
                if ( alice[j] > 0 && maxA < alice[j] ){
                    maxA    = alice[j];
                    indexA  = j;
                }
            }
            // Identify max card of Bob.
            for( int j{0}; j < n; j++){
                if ( bob[j] > 0 && maxB < bob[j] ){
                    maxB    = bob[j];
                    indexB  = j;
                }
            }

            
        }
    }

    return 0;
}