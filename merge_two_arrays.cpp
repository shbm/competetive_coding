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

vector<int> merge(vector<int> &A, vector<int> &B) {
    vector<int > c;
    int i = 0, j = 0;
    while(i < A.size() && j < B.size()) {
        int a = A[i];
        int b = B[j];
        if(a > b) {
            c.push_back(b);
            j++;
        } else {
            c.push_back(a);
            i++;
        }
    }
    if(i < A.size()) {
        for(int k = i; k < A.size(); k++) {
            c.push_back(A[k]);
        }
    }
    if(j < B.size()) {
        for(int k = j; k < B.size(); k++) {
            c.push_back(B[k]);
        }
    }
    return c;
}

int main() {
    clock_t tStart = clock();

    vector<int > A {1,5,8};
    vector<int> B {6, 9};
    cout << merge(A, B);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
