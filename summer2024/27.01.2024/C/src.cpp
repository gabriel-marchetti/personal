#include <bits/stdc++.h>

void printVector( const std::vector<int> &vector ){
    for( int i{0}; i < vector.size(); i++ ){
        std::cout << vector[i] << ' ';
    }
    std::cout << '\n';
}

int main( ){
    int n;
    std::cin >> n;
    std::vector<int> piecesOfBigNum;

    long long read{0};
    for( int i{0}; i < n; i++ ){
        std::cin >> read;
        piecesOfBigNum.push_back(read);
    }

    sort(piecesOfBigNum.begin(), piecesOfBigNum.end());
    reverse(piecesOfBigNum.begin(), piecesOfBigNum.end());
    //printVector(piecesOfBigNum);
    long long sumAlice{0}, sumBob{0};
    for( int i{0}; i < n; i++ ){
        if( i % 2 ){
            sumBob += piecesOfBigNum[i];
        } else {
            sumAlice += piecesOfBigNum[i];
        }
    }

    std::cout << sumAlice << ' ' << sumBob << '\n';
    return 0;
}