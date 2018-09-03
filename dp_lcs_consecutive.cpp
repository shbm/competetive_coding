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

void lcs(string a, string b, int m, int n) {
    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    // store the max length and the index at which it will end;
    int max_len = 0,
        ending_len = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {

            //check if the last characters of both strings are equal
            if(a[i-1] == b[j-1]) {

                // update the dp table
                dp[i][j] = dp[i-1][j-1]+1;

                // if there is the matching lenght of mroe the max_len
                if(dp[i][j] > max_len) {

                    //update the max_len
                    max_len = dp[i][j];
                    // update the ending_len
                    ending_len = i;
                }
            }
        }
    }
    cout << a.substr(ending_len-max_len, ending_len);
}

int main() {
    clock_t tStart = clock();

    string X = "BABAC", Y = "BABA";
    int m = X.length(), n = Y.length();

    lcs(X, Y ,n ,n);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
