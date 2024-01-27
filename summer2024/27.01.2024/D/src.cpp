#include <bits/stdc++.h>

int main( ){
    int testCases{0};
    std::cin >> testCases;
    
    int n{0};
    long long sum{0};
    std::vector<long long> sizes;
    while(testCases--){
        sum = 0;
        n = 0;
        sizes.clear();
        std::cin >> n;
        for( int i{0}, aux{0}; i < n; i++ ){
            std::cin >> aux;
            sizes.push_back(aux);
        }
        std::sort( sizes.begin(), sizes.end() );

        int storeSum{0};
        while( sizes.size() != 1 ){
            storeSum = sizes[0] + sizes[1];
            sum += storeSum;

            sizes.erase( sizes.begin(), sizes.begin() + 2 );
            auto it = std::lower_bound( sizes.begin(), sizes.end(), storeSum );
            sizes.insert(it, storeSum);
        }

        std::cout << sum << '\n';
    }

    return 0;
}