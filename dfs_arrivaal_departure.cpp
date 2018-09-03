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

        void display_graph() {
            for(int i = 0; i < N; i++) {
                cout << i << " -> ";
                for(auto &k: adjList[i]) {
                    cout << k << " ";
                }
                cout << "\n";
            }
        }

        void dfs(vector<bool> visited, int src);
        void bfs(vector<bool> visited, int src);
        void dfs_arrival_departure(vector<bool> &visited, int src, vector<int> &arrival, vector<int> &departure, int &time);
        ~Graph() {
            delete[] adjList;
        }
};


void Graph::dfs(vector<bool> visited, int src) {
    visited[src] = true;
    cout << src << " ";
    for(auto &i: adjList[src]) {
        if(!visited[i]) {
            dfs(visited, i);
        }
    }
}

void Graph::bfs(vector<bool> visited, int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for(auto &i: adjList[node]) {
            if(!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}


void Graph::dfs_arrival_departure(vector<bool> &visited, int src, vector<int> &arrival, vector<int> &departure, int &time) {

    visited[src] = true;
    arrival[src] = ++time;
    for(auto &i: adjList[src]) {
        if(!visited[i]) {
            dfs_arrival_departure(visited, i, arrival, departure, time);
        }
    }
    departure[src] = ++time;
}


int main() {
    clock_t tStart = clock();
    vector<Edge> edges = { 
        {0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5}, 
        {4, 5}, {6, 7}
    };

    int N = 8;
    Graph graph(edges, N);

    vector<bool> visited(N, false);
    vector<int> arrival(N);
    vector<int> departure(N);
    int time = 0;

    int src = 0;
    for (int i = 0; i < N; i++)
        if (!visited[i])
            graph.dfs_arrival_departure(visited, i, arrival, departure, time);

        for (int i = 0; i < N; i++)
        cout << "Vertex " << i << " (" << arrival[i]
             << ", " << departure[i] << ")" << endl;



    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
