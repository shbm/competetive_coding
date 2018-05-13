#include <stdio.h>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
    public:
        Graph(int V);
        void add_edge(int v, int w);
        void BFS(int source);
};

Graph::Graph(int vertices) {
    this->V = vertices;
    adj = new list<int>[V];
}

void Graph::add_edge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int source) {
    bool *visisted = new bool[V];
    for(int i = 0; i < V; i++) {
        visisted[i] = false;
    }
    list<int> queue;
    visisted[source] = true;
    list<int>::iterator i;

    queue.push_back(source);

    while(!queue.empty()) {
        source = queue.front();
        cout << source << "\n";

        queue.pop_front();

        for(i = adj[source].begin(); i != adj[source].end(); i++) {
            if(!visisted[*i]) {
                visisted[*i] = true;
                queue.push_back(*i);
            }
        }

    }
}

int main() {

    Graph g(4);
    g.add_edge(1, 2);
    g.add_edge(0, 2);
    g.add_edge(3, 2);
    g.add_edge(3, 0);
    g.BFS(3);
    return 0;
}
