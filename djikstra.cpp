#include <stdio.h>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>

# define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main() {
    int V = 9, m = 14;
    vector<pair<int, int> > g[V];
    int u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(w, v));
        g[v].push_back(make_pair(w, u));
    }
    for(int i = 0; i < V; i++) {
        cout << i << "\n----";
        for(const auto& to : g[i]) {
            cout << to.second << "\t";
        }
        cout << "\n";
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int source = 0;
    vector<int> dist(V, INF);
    dist[source] = 0;
    pq.push(make_pair(0, source));
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(const auto& i : g[u]) {
            int v = i.second;
            int weight = i.first;
            if(dist[v] > dist[u] + weight) {

                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }

    }
    for(int i = 0; i < V; i++) {
        cout << "\n" << dist[i];
    }
}