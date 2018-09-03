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

map<pair<int, int>, int> h;

void indent(int k) {
    for(int i = 0; i < k; i++)
    cout << "   ";
}

int chain(vector<int> &a, int i, int j) {
    indent(i);
    cout << "chain(" << i << ", " << j << ")\n";
    if(h.find(make_pair(i, j)) != h.end()) {
        return h[make_pair(i, j)];
    }
    if(i == j) {
        return 0;
    }

    int k;
    int m = INT_MAX;

    for(int k = i; k < j; k++) {
        m = min(m, chain(a, i, k) + chain(a, k+1, j) + a[i-1]*a[k]*a[j]);
    }
    h[make_pair(i, j)] = m;
    return m;
}


int main() {
    clock_t tStart = clock();

    vector<int > a{1,2,3,4};
    cout << chain(a, 1, a.size()-1);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
