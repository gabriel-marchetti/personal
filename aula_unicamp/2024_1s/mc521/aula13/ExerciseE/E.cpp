#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;

enum { UNVISITED = -1, VISITED = -2 };

// Union-Find Disjoint Sets Library
class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;

public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }

    int numDisjointSets() {
        return numSets;
    }

    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }
};

void dfs(int u, int target, 
         const vector<vector<pair<int, int>>> &AL, 
         vi &dfs_num, 
         int &max_dist, 
         int current_max) {
    if (u == target) {
        max_dist = max(max_dist, current_max);
        return;
    }

    dfs_num[u] = VISITED;
    for (auto &[w, v] : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs(v, target, AL, dfs_num, max_dist, max(current_max, w));
        }
    }
}

int main() {
    int V, E, Q;
    int number = 0;
    while (true) {
        cin >> V >> E >> Q;
        if (V == 0 && E == 0 && Q == 0) break;

        vector<iii> EL(E);
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            EL[i] = {w, u, v};
        }

        sort(EL.begin(), EL.end());
        UnionFind UF(V);

        vector<vector<pair<int, int>>> adj_list(V);
        int num_taken = 0;
        for (int i = 0; i < E; ++i) {
            auto [w, u, v] = EL[i];
            if (UF.isSameSet(u, v)) continue;
            UF.unionSet(u, v);
            adj_list[u].push_back({w, v});
            adj_list[v].push_back({w, u});
            ++num_taken;
            if (num_taken == V - 1) break;
        }

        printf("Case #%d\n", ++number);
        for (int i = 0; i < Q; ++i) {
            int iQ, fQ;
            cin >> iQ >> fQ;
            vi dfs_num(V, UNVISITED);
            int max_road = -1;
            dfs(iQ, fQ, adj_list, dfs_num, max_road, 0);
            if (dfs_num[fQ] == UNVISITED) {
                printf("no path\n");
            } else {
                printf("%d\n", max_road);
            }
        }
        printf("\n");
    }

    return 0;
}
