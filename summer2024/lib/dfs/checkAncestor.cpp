// Check if a vertex is an ancestor of another in 
// a tree
#include <bits/stdc++.h>

const int MAXN = 100010;

std::vector<int> grafo[MAXN];
int entry_array[MAXN]{0}, exit_array[MAXN]{0}, marcv[MAXN]{0},
    time_aux{0}, exit_aux{0};

void printAdjacencia( std::vector<int> G[], int nodes ){
    for(int i{1}; i <= nodes; i++){
        std::cout << i << " => ";
        for( int j{0}; j < G[i].size(); j++ ){
            std::cout << G[i][j] << ' ';
        }
        printf("\n");
    }
}

void dfs( int vertex ){
    marcv[vertex] = 1;
    entry_array[vertex] = time_aux;
    time_aux++;

    for( int i{0}; i < grafo[vertex].size(); i++ ){
        int neighboor = grafo[vertex][i];
        if( marcv[neighboor] == 0 ){
            dfs( neighboor );
        }
    }

    exit_array[vertex] = exit_aux;
    exit_aux++;
}

bool checkAncestrality( int ancestor, int precessor ){
    if( entry_array[ancestor] < entry_array[precessor] &&
        exit_array[ancestor] > exit_array[precessor] 
    ){
        return true;
    }

    return false;
}

int main( ){
    /*
             1
           /  \
          2   3
         /   / \
        4   5  6
    */
   
    int n, m;
    int node1, node2;
    std::cin >> n >> m;
    for( int i{0}; i < m; i++ ){
        std::cin >> node1 >> node2;
        grafo[node1].push_back(node2);
        grafo[node2].push_back(node1);
    }

    printAdjacencia(grafo, n);

    dfs(1);
    // check if 2 is ancestor of 4 (true);
    std::cout << checkAncestrality(2, 4) << '\n';

    // check if 2 is ancestor of 5 (false);
    std::cout << checkAncestrality(2, 5) << '\n';

    // check if 1 is ancestor of 5 (true);
    std::cout << checkAncestrality(1, 5) << '\n';

    // check if 1 is ancestor of 6 (true);
    std::cout << checkAncestrality(1, 6) << '\n';

}