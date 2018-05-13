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

void BFS(vector<int> g[], int s, vector<bool> discovered) {
    queue<int> q;
    q.push(s);
    discovered[s] = true;
    while(!q.empty()) {
        s = q.front();
        cout << s << "\t";
        q.pop();
        for(const auto& i: g[s]) {
            if(!discovered[i]) {
                q.push(i);
                discovered[i] = true;
            }
        }
    }
}

int main() {
    int V = 8+1;
    vector<Edge> edges = {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}
    };

    vector<int> g[V];
    for(const auto& i: edges) {
        g[i.src].push_back(i.dest);
        g[i.dest].push_back(i.src);
    }
    vector<bool> discovered(V, false);
    int source = 1;
    BFS(g, source, discovered);
    return 0;
}
