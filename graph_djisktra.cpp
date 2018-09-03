#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
 
// Data structure to store graph edges
struct Edge {
    int source, dest, weight;
};
 
// data structure to store heap nodes
struct Node {
    int vertex, weight;
};
 
// class to represent a graph object
class Graph
{
    public:
    // An array of vectors to represent adjacency list
    vector<Edge> *adjList;
 
    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // allocate memory
        adjList = new vector<Edge>[N];
 
        // add edges to the undirected graph
        for (Edge const &edge: edges)
        {
            // insert at end
            adjList[edge.source].push_back(edge);
        }
    }
 
    // Destructor
    ~Graph() {
        delete[] adjList;
    }
};

struct compare {
    inline bool operator() (Node const &a, Node const &b) {
        return a.weight > b.weight;
    }
};

// We need to sort using the closer distnace from the source.
// So we take weight in the Node struct

void djikstra(Graph const& graph, int source, int N) {
    priority_queue<Node, vector<Node>, compare> pq;
    Node n = {1,2};
    pq.push({source, 0});
    vector<int> visited(N, 0);
    vector<int> distance(N, INT_MAX);
    distance[source] = 0;
    visited[source] = true;
    while(!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        for(auto &i: graph.adjList[u]) {
            int v = i.dest;
            int weight = i.weight;
            if(!visited[v] && distance[u]+weight < distance[v]) {
                distance[v] = distance[u]+weight;
                pq.push({v, distance[v]});
            }
        }
    }
    for(int i = 0; i < N; i++) {
        cout << i << " " << distance[i] << "\n";
    }
}

int main() {
    clock_t tStart = clock();

    
    vector<Edge> edges =
    {
        {0, 1, 10}, {0, 4, 3}, {1, 2, 2}, {1, 4, 4}, {2, 3, 9},
        {3, 2, 7}, {4, 1, 1}, {4, 2, 8}, {4, 3, 2}
    };
 
    // Number of nodes in the graph
    int N = 5;
 
    // construct graph
    Graph graph(edges, N);
    djikstra(graph,0, N);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
