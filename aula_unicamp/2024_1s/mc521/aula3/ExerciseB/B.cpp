#include <bits/stdc++.h>

using namespace std;

class UnionFind{
    /*
     * Classe retirada da vídeo-aula.
     */
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
    ios::sync_with_stdio(false);
    int N, Q;
    //cin >> N >> Q;
    scanf("%d %d\n", &N, &Q);

    char operation;
    int num1, num2;
    UnionFind UF(N);
    for( int i{0}; i < Q; i++ ){
        scanf("%c %d %d\n", &operation, &num1, &num2);
        //cin >> operation >> num1 >> num2;
        //cout << operation << num1 << num2;
        if( operation == '?' ){
            if( UF.isSameSet(num1, num2) )
                printf("yes\n");
                //cout << "yes\n";
            else
                printf("no\n");
                //cout << "no\n";
        } else if ( operation == '=' ) {
            UF.unionSet(num1, num2);
        } 
    }

    return 0;
}