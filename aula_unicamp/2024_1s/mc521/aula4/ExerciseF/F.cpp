#include <bits/stdc++.h>

int main(){
    std::vector<int> numbers;
    int n, tmp;
    
    std::map<int, std::pair<int, int>> sumsAndIndexes;
    while( scanf("%d", &n), n ){
        
        for( int i{0}; i < n; i++ ){
            scanf("%d", &tmp);
            numbers.push_back(tmp);
        }

        for(int i{0}; i < numbers.size() - 1; i++){
            for(int j{i+1}; j < numbers.size(); j++){
                sumsAndIndexes.insert( numbers[i] + numbers[j], std::make_pair(i, j));
            }
        }

    }

    return 0;
}