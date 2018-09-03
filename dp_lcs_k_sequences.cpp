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

int max(int a, int b, int c) {
    return max(a, max(b,c));
    //return a > b ? a > c ? a : c : b > c ? b : c;
}

int lcs(string a, string b, string c, int m, int n, int o) {
    if(m == 0 || n ==0 || o ==0) {
        return 0;
    }
    if(a[m-1] == b[n-1] && b[n-1] == c[o-1]) {
        return 1+lcs(a, b, c, m-1, n-1, o-1);
    } else {
        return max(
                lcs(a, b, c, m-1, n, o),
                lcs(a, b, c, m, n-1, o),
                lcs(a, b, c, m, n, o-1)
                );
    }
}

int main() {
    clock_t tStart = clock();

    string X = "ABCBDAB",
           Y = "BDCABA",
           Z = "BADACB";

    int m = X.length();
    int n = Y.length();
    int o = Z.length();

    cout << lcs(X,Y,Z,m,n,o);
    cout << "\n" << (2 == 2 == 2) << "\n";

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
