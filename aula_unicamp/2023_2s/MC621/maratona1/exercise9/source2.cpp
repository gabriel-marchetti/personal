#include <bits/stdc++.h>

int main(void)
{
    int t, n, m;
    int maxA, maxB;
    int read;
    std::cin >> t;
    for( int j{0}; j < t; j++ ){
        maxA = -1;
        maxB = -1;
        std::cin >> n;
        for(int i{0}; i < n; i++){
            std::cin >> read;
            if( read > maxA ) maxA = read;
        }
        std::cin >> m;
        for(int i{0}; i < m; i++){
            std::cin >> read;
            if( read > maxB ) maxB = read;
        }

        if( maxA == maxB ){
            std::cout << "Alice" << std::endl;
            std::cout << "Bob" <<  std::endl;
        } else if ( maxA > maxB ){
            std::cout << "Alice" << std::endl;
            std::cout << "Alice" << std::endl;
        } else {
            std::cout << "Bob" <<  std::endl;
            std::cout << "Bob" <<  std::endl;
        }

    }

    return 0;
}