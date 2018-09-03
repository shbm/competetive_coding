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

vector<vector<int> > prettyPrint(int A) {
    vector<vector<int> > v;
    vector<int> r(A*2-1, A);
    v.push_back(r);
    for(int i = 1; i < A; i++) {
        for(int j = i; j < A*2-i-1; j++) {
            r[j] = A-i;
        }
        v.push_back(r);
    }

    vector<int> idx;
    for(int i = A; i < A*2-1; i++) {
        idx.push_back(i-A);
    }
    reverse(idx.begin(), idx.end());
    for(int i: idx) {
        v.push_back(v[i]);
    }

    return v;
}


int main() {
    clock_t tStart = clock();

    cout <<    prettyPrint(4);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
