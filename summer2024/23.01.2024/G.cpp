#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100010;

vector<int> grafo[MAXN];
int marc[MAXN]{0}, luckyCities[MAXN]{0};

void dfs( int v, int tempo ){
    marc[v] = 1;
    int numOfNeighbor = grafo[v].size();
    bool entreiNoLoop = false;
    for( int i = 0 ; i < numOfNeighbor ; i++ ){
        int viz = grafo[v][i];
        if ( marc[viz] == 0 ){
            dfs( viz, tempo + 1 );
            entreiNoLoop = true;
        }        
    }
    // Se eu não entrei no loop significa que não tenho vizinhos não-visitados,
    // Para checar se é "luckyCity" basta ver se o tamanho do caminho é ímpar.
    if( !entreiNoLoop && tempo % 2 ){
        luckyCities[v] = 1;
    }
}

int main(void){
    int T{0}, M{0}, N{0},
        node1, node2;
    freopen("d.in", "r", stdin);
    cin >> T;
    //cout << T << '\n';
    for(int i{0}; i < T; i++){

        cin >> M >> N;
        for(int j{0}; j < N; j++){
            cin >> node1 >> node2;
            grafo[node1].push_back(node2);
            grafo[node2].push_back(node1);
        }

        dfs(1, 1);

        int numOfLuckyCities{0};
        for(int j{0} ; j < M ; j++)
            if( luckyCities[j] == 1 ) numOfLuckyCities++;

        cout << numOfLuckyCities << '\n';
        // Preciso limpar para a próxima iteração.
        for(int j{0}; j < M; j++){
            grafo[j].clear();
            marc[j] = 0;
            luckyCities[j] = 0;
        }
    }
}