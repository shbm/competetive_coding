#include <stdio.h>
#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) for (int i = a; i < b; i++)

struct DisjointSets {
    int *parent, *rnk;
    int n;
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

int main() {
    int V = 9, m = 14;
    int u, v, w;
    vector<pair<int, pair<int, int> > > g;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g.push_back({w, {u, v}});
    }
    sort(g.begin(), g.end());
    int mst = 0;
    DisjointSets ds(V);
    for(const auto& i : g) {
        int u = i.second.first;
        int v = i.second.second;

        int set_v = ds.find(v);
        int set_u = ds.find(u);

        if(set_u != set_v) {
            cout << "\n" << u << " - " << v;
            mst += i.first;
            ds.merge(set_u, set_v);
        }
    }
    cout << mst;
    return 0;
}
