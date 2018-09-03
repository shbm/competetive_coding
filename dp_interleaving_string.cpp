#include <stdio.h>
#include <queue>
#include <sstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <time.h>
#include <bitset>
#include <climits>

using namespace std;


template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const set<T>& v)
{
    os << "[";
    for (auto it : v) {
        os << it;
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "]\n";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v)
{
    os << "(";
    os << v.first << ", "
        << v.second << ")";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v)
{
    for (auto it : v)
        os << it.first << " : "
            << it.second << "\n";

    return os;
}

bool is_interleaved(string A, string B, string C) {
    int M = A.length();
    int N = B.length();

    if(M+N != C.length()) {
        return 0;
    }
    vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
    cout << dp;

    //int dp[M+1][N+1];
    //for(int i = 0; i <= M+1; i++) {
        //for(int j = 0; j <= N+1; j++) {
            //cout << 0 << " ";
        //}
        //cout << "\n";
    //}
    //memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= M; i++) {
        for(int j = 0; j <= N; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
            }

            if(i == 0 && B[j-1] == C[i+j-1]) {
                dp[i][j] = dp[i][j-1];
            }

            if(j == 0 && A[i-1] == C[i+j-1]) {
                dp[i][j] = dp[i-1][j];
            }

            if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1]) {
                dp[i][j] = dp[i-1][j];
            }

            if(A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1]) {
                dp[i][j] = dp[i][j-1];
            }

            if(A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1]) {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    return dp[M][N];
}

int main() {
    clock_t tStart = clock();

    string A = "T5okte43ByvdK7vE5mkoqBsBaYkbbcuJXbeuvkAvTIO";
    string B = "UzrGYRGazimUVuOPfUUrZrFyF";
    string C = "UT5ozkrtGYe4RG3ByazvdimUVuKO7vE5mkoPqBfUsUBaYrZrkbFbcuyFJXbeuvkAvTIO";

    //cout << is_interleaved(A, B, C);
    map<char, int> m;
    string c = "hackerrank";
    for(char i: c) {
        m[i]++;
    }

    cout << m;

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
