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

class DisjointSet {
    unordered_map<int, int> rank;
    public:
    unordered_map<int, int> parent;
    void makeset(vector<int> univerese) {
        for(const auto& i : univerese) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int Find(int x) {
        if(parent[x] != x)
            parent[x] = Find(x);
        return parent[x];
    }

    void Union(int a, int b) {
        int x = Find(a);
        int y = Find(b);

        if(x == y) return;

        if(rank[x] > rank[y]) {
            parent[y] = x;
        } else if(rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[x] = y;
            rank[y]++;
        }
    }
};

void printSets(vector<int> u, DisjointSet ds) {
    for(int i : u) {
        cout << ds.Find(i) << " ";
    }
    cout << "\n";
}

int main() {

    DisjointSet ds;

    vector<int> univerese = {1,2,3,4,5};
    ds.makeset(univerese);
    ds.Union(1,2);
    ds.Union(3,1);
    //for(const auto& i : ds.parent) {
        //cout << i.first << " -> " << i.second;
        //cout << "\n";
    //}
    //printSets(univerese, ds);
    return 0;
}
