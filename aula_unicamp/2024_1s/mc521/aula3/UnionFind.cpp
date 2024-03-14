#include <bits/stdc++.h>

using namespace std;

class UnionFind{
    private:
        vector<int> p, rank, setSize;
        int numSets;
    public:
        UnionFind(int N){
            setSize.assign(N, 1);
            numSets = N;
            rank.assign(N, 0);
            p.assign(N, 0);
            for(int i{0}; i < N; i++){
                p[i] = i;
            }
        }
        int findSet(int i){
            return ( p[i] == i ) ? i : ( p[i] = findSet(p[i]) ); 
        }
        bool isSameSet( int i, int j ){
            return findSet(i) == findSet(j);
        }
        void unionSet( int i, int j ){
            if( !isSameSet(i, j) ){
                numSets--;
                int rI = findSet(i), rJ = findSet(j);

                if( rank[rI] > rank[rJ] ){
                    p[rJ] = rI;
                    setSize[rI] += setSize[rJ];
                }
                else{
                    p[rI] = rJ;
                    setSize[rJ] += setSize[rI];
                    if( rank[rJ] == rank[rI] )
                        rank[rJ]++;
        }}}
        int numDisjoitSets(){ return numSets; }
        int sizeOfSet( int i ){ return setSize[findSet(i)]; }
};

int main(){
    printf("Assume that we start with 5 disjoint sets.\n");
    UnionFind UF(5);
    printf("%d\n", UF.numDisjoitSets());
    UF.unionSet(0, 1);
    printf("%d\n", UF.numDisjoitSets());
    UF.unionSet(2, 3);
    printf("%d\n", UF.numDisjoitSets());
    UF.unionSet(4, 3);
    printf("%d\n", UF.numDisjoitSets());

    printf("isSameSet(0, 3) = %d\n", UF.isSameSet(0,3));
    printf("isSameSet(4, 3) = %d\n", UF.isSameSet(4, 3));

    for(int i{0}; i < 5; i++){
        printf("findSet(%d) = %d and sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    }

    UF.unionSet(0, 3);
    printf("%d\n", UF.numDisjoitSets());

    for(int i{0}; i < 5; i++){
        printf("findSet(%d) = %d and sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    }

    return 0;
}