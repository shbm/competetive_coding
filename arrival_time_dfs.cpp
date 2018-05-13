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

#define N 5

struct Edge {
    int src;
    int dest;
};


int main() {
    clock_t tStart = clock();

    cout << "http://www.techiedelight.com/arrival-departure-time-vertices-dfs/\n";

    vector<Edge> edges = {
        {0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4}, {3, 1}, {3, 2}, {4, 3}
    };

    vector<int> adjacecny_list[N];
    for(auto &i : edges) {
        adjacecny_list[i.src].push_back(i.dest);
        adjacecny_list[i.dest].push_back(i.src);
    }

    for(int i = 0; i < N; i++) {
        cout << i << " ";
        for(int j = 0; j < adjacecny_list[i].size(); j++) {
            cout << adjacecny_list[i][j] << " ";
        }
        cout << "\n";
    }

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
