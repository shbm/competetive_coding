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

using namespace std;

map<pair<int, int>, int> cache;

int palin(string a, int i, int j) {
    if(cache.find(make_pair(i,j)) != cache.end()) {
        return cache[make_pair(i,j)];
    }
    if (i == j) {
        return 1;
    }

    if(a[i] == a[j] && i+1 == j) {
        cache[make_pair(i, j)] = 2;
    }

    if(a[i] == a[j]) {
        cache[make_pair(i, j)] = palin(a, i+1, j-1) + 2;
    }

    if(a[i] != a[j]) {
        int l1 = palin(a, i, j-1);
        int l2 = palin(a, i+1, j);
        cache[make_pair(i, j)] = max(l1, l2);
    }
    return cache[make_pair(i,j)];
}

int main() {
    clock_t tStart = clock();
    string s = "saras";
    cout << palin(s, 0, s.length());
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
