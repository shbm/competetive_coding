#include <stdio.h>
#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>

using namespace std;

class DisjointSet {
    public:
        map<int, int> parent;
        map<int, int> rank;
        void make_set(int N) {
            for(int i = 0; i < N; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int k) {
            if(parent[k] == k) {
                return k;
            }
            return find(parent[k]);
        }

        void merge(int x, int y) {
            int findX = find(x);
            int findY = find(y);
            if(findX == findY) {
                return;
            }
            if(rank[findX] < rank[findY]){
                parent[findX] = findY;
            } else if(rank[findX] > rank[findY]) {
                parent[findY] = findX;
            } else {
                parent[findX] = findY;
                rank[findY]++;
            }
        }

        void print_set(vector<int> &u) {
            for(auto &i: u) {
                cout << find(i) << " ";
            }
        }
};

struct Edge {
    int src, dest, weight;
};

struct compare {
    inline bool operator() (Edge const &a, Edge const &b) {
        return (a.weight > b.weight);
    }
};

vector<Edge> mst(vector<Edge> edges, int N) {
    DisjointSet ds;
    ds.make_set(N);
    vector<Edge> MST;
    while(MST.size() != N-1) {
        Edge e = edges.back();
        edges.pop_back();
        int x = ds.find(e.src);
        int y = ds.find(e.dest);

        if(x!=y) {
            ds.merge(e.src, e.dest);
            MST.push_back(e);
        }

    }
    return MST;
}

int main(int argc, char *argv[]) {

    vector<Edge> edges = {
        // (u, v, w) tiplet represent undirected edge from
        // vertex u to vertex v having weight w
        { 0, 1, 7 }, { 1, 2, 8 }, { 0, 3, 5 }, { 1, 3, 9 }, 
        { 1, 4, 7 }, { 2, 4, 5 }, { 3, 4, 15 }, { 3, 5, 6 }, 
        { 4, 5, 8 }, { 4, 6, 9 }, { 5, 6, 11 }
    };

    int N = 7;

    sort(edges.begin(), edges.end(), compare());
    for(auto &i: edges) {
        cout << i.weight << " ";
    }
    cout << "\n";
    vector<Edge> M = mst(edges, N);
    for(auto &i: M) {
        cout << i.src << " " << i.dest << " " << i.weight << "\n";
    }

    return 0;
}
