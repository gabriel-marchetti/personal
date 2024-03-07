#include <bits/stdc++.h>

using namespace std;

void swap( int x, int y ){
    
}

class UnionFind {
    private:
        vector<int> parent, rank, setSize;
        int numSets;
    public:
        // Construtor
        UnionFind( int N ){
            parent.assign(N, 0);
            for( int i{0}; i < N; i++ )
                parent[i] = i;
            rank.assign(N, 0);
            setSize.assign(N, 1);
            numSets = N;
        }

        int findSet( int i ){
            return ( parent[i] == i ) ? i : parent[i] = findSet(parent[i]);  
        }

        bool isSame( int i, int j ){
            return findSet(i) == findSet(j);
        }

        int numDisjointSets(){ return numSets; }

        int sizeOfSet( int i ){
            return setSize[findSet(i)];
        }

        void UnionSet( int i, int j ){
            if( isSame(i, j) ) return;

        }
}