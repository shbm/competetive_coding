#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

struct Edge {
    int src, dest;
};

void DFS(vector<int> g[], int source, vector<bool> discovered) {
    discovered[source] = true;
    cout << "\t" << source;

    for(int u: g[source]) {
        if(!discovered[u]) {
            DFS(g, u, discovered);
        }
    }
}

int main() {

    int V = 8+1;
    vector<Edge> edges = {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}
    };

    cout << edges.size() << "\n";
    vector<int> g[V];

    for(const auto& i: edges) {
        g[i.src].push_back(i.dest);
        g[i.dest].push_back(i.src);
    }

    vector<bool> discovered(V, false);
    DFS(g, 1, discovered);
    return 0;
}
