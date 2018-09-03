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
#include <algorithm>
#include <climits>

using namespace std;


int lcp(string a, int i, int j) {
    if(i > j) {
        return 0;
    }
    if(i == j) {
        return 1;
    }

    if(a[i] == a[j])
        return lcp(a, i+1, j-1) + 2;
    else
        return max(lcp(a, i+1, j), lcp(a, i, j-1));
}


int main() {
    clock_t tStart = clock();

    string X = "ABBDCACB";
    int n = X.length();
    cout << "The length of Longest Palindromic Subsequence is "
            << lcp(X, 0, n - 1);


    string a = "ABBDCACB";
    string b = a;
    reverse(b.begin(), b.end());
    cout << a <<  " " << b << " ";
    int dp[20][20];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i, j;
    i = n, j = n;
    int index = dp[n][n];
    string lcs(10,'\0');
    while(i>0 && j > 0){
        if(a[i-1] == b[j-1]) {
            lcs[index-1] = a[i-1];
            i--;
            j--;
            index--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << " - " << lcs << "\n\n";

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
