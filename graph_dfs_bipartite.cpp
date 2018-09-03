// GRAPH
#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <unordered_map>
#include <time.h>
#include <climits>

using namespace std;

struct Edge {
    int src, dest;
};

class Graph {
    public:
        vector<int> *adjList;
        int N;

        Graph(vector<Edge> edges, int n) {
            N = n;
            adjList = new vector<int>[N];
            for(auto &i: edges) {
                int src = i.src;
                int dest = i.dest;
                adjList[src].push_back(dest);
                adjList[dest].push_back(src);
            }
        }

        ~Graph() {
            delete[] adjList;
        }
};

bool bipartite_check_dfs(Graph const &g, int v, vector<bool> visited, vector<bool> color) {
    for(auto &u: g.adjList[v]) {
        if(!visited[u]) {
            visited[u] = true;
            color[u] = !color[v];
            if(bipartite_check_dfs(g, u, visited, color))
                 return false;
        } else if(color[u] == color[v])
            return false;
    }
    return true;
}
int main() {
    clock_t tStart = clock();

    vector<Edge> edges = {
            // Notice that node 0 is unconnected node
            {0, 1},{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
            {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {2, 7}
        };

    int N = 13;
    Graph graph(edges, N);

    vector<bool> visited(N, 0);
    vector<bool> color(N);
    color[0] = 0;
    visited[0] = true;
    cout << bipartite_check_dfs(graph, 0, visited, color);


    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
