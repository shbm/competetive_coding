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
            }
        }

        ~Graph() {
            delete[] adjList;
        }
};

void topological_sort(Graph const &g, int v, vector<int> &departure, vector<bool> &visited, int &time) {
    visited[v] = 1;
    time++;
    for(auto &u : g.adjList[v]) {
        if(!visited[u]) {
            topological_sort(g, u,departure, visited, time);
        }
    }
    departure[time] = v;
    time++;
}

int main() {
    clock_t tStart = clock();

    vector<Edge> edges = {
        {0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4},
        {5, 1}, {7, 0}, {7, 1}
    };

    // Number of nodes in the graph
    int N = 8;

    Graph graph(edges, N);

    vector<int> departure(2*N, -1);
    vector<bool> visited(N, 0);

    int time = 0;
    for(int src = 0; src < N; src++)
        if(visited[src] == 0)
            topological_sort(graph, src, departure, visited, time);
    for(auto &i: departure) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 2*N - 1; i >= 0; i--)
        if (departure[i] != -1)
            cout << departure[i] << " ";


    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


