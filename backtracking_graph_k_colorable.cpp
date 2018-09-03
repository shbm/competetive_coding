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

// class to represent a graph object
class Graph
{
    public:
    // An array of vectors to represent adjacency list
    vector<int> *adj;

    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // allocate memory
        adj = new vector<int>[N];

        // add edges to the undirected graph
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
    }
};

string COLORS[] = {"", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE",
                "PINK", "BLACK", "BROWN", "WHITE", "PURPLE"};

bool is_safe(Graph const &g, vector<int> color, int c, int v) {
    for(auto &u: g.adj[v]) {
        if(color[u] == c) {
            return false;
        }
    }
    return true;
}

void kColorable(Graph const &g, vector<int> color, int k, int v, int N) {
    if(v == N) {
        for(int i = 0; i < N; i++) {
            cout << COLORS[color[i]] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= k; i++) {
        if(is_safe(g, color, i, v)) {
            color[v] = i;
            kColorable(g, color, k, v+1, N);
            color[v] = 0;
        }
    }
}

int main() {
    clock_t tStart = clock();

    vector<Edge> edges =
    {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
    };

    // Number of vertices in the graph
    int N = 6;

    // create a graph from edges
    Graph g(edges, N);

    int k = 3;

    vector<int> color(N, 0);

    // print all k-colorable configurations of the graph
    kColorable(g, color, k, 0, N);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
