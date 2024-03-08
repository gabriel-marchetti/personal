#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    long long reader, doubledCD{0};
    map<long long, int> CDs;

    while( true ){
        doubledCD = 0;
        CDs.clear();
        cin >> N >> M;
        if( N == 0 && M == 0 ) break;

        for(int i{0}; i < N; i++){
            cin >> reader;
            CDs.insert({reader, 1});
        }

        for(int i{0}; i < M; i++){
            cin >> reader;
            auto iterator = CDs.find(reader);
            if( iterator->second == 1 )
                doubledCD++;
        }

        cout << doubledCD << endl;
    }

    return 0;
}