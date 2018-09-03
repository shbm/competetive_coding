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

int minimum(int a, int b, int c) {
    return min(a, min(b,c));
}

int edit_distance(string p, string q, int m, int n) {
    if(m==0) return n;
    if(n == 0) return m;

    if(p[m-1] == q[n-1])
        return edit_distance(p, q, m-1, n-1);

    return 1 + minimum(edit_distance(p, q, m-1, n),
            edit_distance(p, q, m, n-1),
            edit_distance(p, q, m-1, n-1));
}



int main() {
    clock_t tStart = clock();

    string p = "sunday";
    string q = "saturday";
    int m = p.length();
    int n = q.length();
    cout << edit_distance(p, q, m, n);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
