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

string longestPalindrome(string A) {
    int N = A.size();
    vector<vector<bool> > P(N+1, vector<bool>(N+1, true));
    int start = 0, len = 1;
    cout << P;

    for (int k = 1; k < N; ++k) {
        for (int i = 1; i <= N-k; ++i) {
            P[i][i+k] = P[i+1][i+k-1] && (A[i-1] == A[i+k-1]);
            if (P[i][i+k] && k+1 > len)
                start = i-1, len = k+1;
        }
    }

    cout << P;

    string result(A.begin() + start, A.begin() + start + len);
    return result;
}


int main() {
    clock_t tStart = clock();

    cout << longestPalindrome("BABAD");

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
