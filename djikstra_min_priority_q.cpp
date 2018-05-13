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

#define REP(i, a, b) for (int i = a; i < b; i++)

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
    priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair <int, int> > > pq;
    int src = 0;
    vector<int> dist(V, INF);
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(const auto& to : g[u]) {
            int v = to.second;
            int w = to.first;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for(const auto& i : dist) {
        cout << "\n" << i;
    }
    return 0;
}

/*
   0 1 4
   0 7 8
   1 2 8
   1 7 11
   2 3 7
   2 8 2
   2 5 4
   3 4 9
   3 5 14
   4 5 10
   5 6 2
   6 7 1
   6 8 6
   7 8 7
   */
