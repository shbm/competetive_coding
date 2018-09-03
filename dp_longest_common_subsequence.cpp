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

int lcs(string a, int m, string b, int n) {

    if(m == 0 || n == 0) {
        return 0;
    }
    if(a[m] == b[n]) {
        return 1+lcs(a, m-1, b, n-1);
    } else {
        return max(lcs(a, m-1, b, n), lcs(a, m, b, n-1));
    }
}

int main() {
    clock_t tStart = clock();

    string X = "ABCBDAB",
           Y = "BDCABA";

    int m = X.length();
    int n = Y.length();

    cout << lcs(X, m, Y, n);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
