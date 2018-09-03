
#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <time.h>
#include <climits>

using namespace std;

void print_vector(vector<int> v) {
    for(auto &i: v) {
        cout << i << " ";
    }
    cout << "\n";
}

int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        cout << i << " : ";
        print_vector(A);
        if (A[i] > 0 && A[i] <= n) {
            int pos = A[i] - 1;
            if (A[pos] != A[i]) {
                swap(A[pos], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) return (i + 1);
    }
    return n + 1;
}


int main() {
    clock_t tStart = clock();

    vector<int> v {-1,-2,-3,1,2,3,5};
    cout << firstMissingPositive(v);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


