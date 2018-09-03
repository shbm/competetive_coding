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


int main() {
    clock_t tStart = clock();

    vector<int> A {3, 34, 4, 12, 5, 2};
    int n = A.size();
    int sum = 9;
    vector<vector<int> > subset(n+1, vector<int> (sum+1, 0));
    for(int i = 0; i <= n; i++) {
        subset[i][0] = 1;
    }

    for(int i = 0; i <= sum; i++) {
        subset[0][i] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < sum; j++) {
            if(j < A[i-1]) {
                subset[i][j] = subset[i-1][j];
            }
            if(j >= A[i-1]) {
                subset[i][j] = subset[i-1][j] || subset[i-1][j-A[i-1]];
            }
        }
    }
    cout << subset;

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
