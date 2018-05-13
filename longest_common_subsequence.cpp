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

int lcs(string a, string b, int m, int n) {
    if(cache.find(make_pair(m, n)) != cache.end()) return cache[make_pair(m,n)];
    int result;
    if(m == 0 || n == 0) {
        return 0;
    }
    if(a[m-1] == b[n-1]) {
        int result = 1 + lcs(a, b, m-1, n-1);
        cache[make_pair(m, n)] = result;
    }
    else {
        int j = lcs(a, b, m-1, n);
        int k = lcs(a, b, m, n-1);
        int result = max(j, k);
        cache[make_pair(m, n)] = result;
    }
    return cache[make_pair(m,n)];
}

int main() {
    clock_t tStart = clock();

    string a = "shubham";
    string b = "sahcuvbbhnaymc";
    cout << (lcs(a, b, a.length(), b.length()));

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
