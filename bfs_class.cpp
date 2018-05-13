#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>

using namespace std;

class Graph {
	private:
		int V;
		list<int> *adj;
	public:
		Graph(int v);
		void BFS(int source);
		void add_edge(int v, int w);
};

Graph::Graph(int vertex) {
	this->V = vertex;
	adj = new list<int>[vertex];
}

void Graph::add_edge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::BFS(int source) {

	bool *visited = new bool[this->V];
	for(int i = 0; i < this-> V; i++)
		visited[i] = false;

	list<int> q;

	visited[source] = true;
	q.push_back(source);

	list<int>::iterator i;

	while(!q.empty()) {
		source = q.front();
		cout << "-" << source << " -- ";
		q.pop_front();

		for(i = adj[source].begin(); i != adj[source].end(); i++) {

			if(!visited[*i]) {
				visited[*i] = true;
				q.push_back(*i);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	Graph g(7);
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 3);
    g.add_edge(4, 2);
    g.add_edge(2, 6);
    g.add_edge(6, 5);
	g.BFS(0);
	return 0;
}