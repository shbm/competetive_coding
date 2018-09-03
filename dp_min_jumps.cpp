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

void indent(int i) {
    while(i--) {
        cout << "|...";
    }
}
map<int, int> cache;
int min_jumps(vector<int> v, int l, int h) {
    indent(l);
    cout << "min_jumps(" << "\"" << l << "\", \"" << h <<"\")" << "\n";
    if(cache.find(l) != cache.end()) {
        return cache[l];
    }
    if(h == l) {
        return 0;
    }
    if(v[l] == 0) {
        return INT_MAX;
    }

    int m = INT_MAX;
    for(int i = l+1; i <= h && i <= l+v[l] ;i++) {
        int jumps = min_jumps(v, i, h);
        if(jumps != INT_MAX)
        m = min(jumps+1, m);
    }
    cout << "\"" << m << "\"" <<"\n";
    cache[l] = m;
    return m;
}

int min_jumps_(vector<int> v) {
    vector<int> jumps(v.size(), INT_MAX);
    jumps[0] = 0;
    for(int i = 1; i < v.size(); i++) {
        for(int j = 1; j < i; j++) {
            if(v[j]+j >= i) {
                jumps[i] = min(jumps[j], jumps[j]+1);
            }
        }
    }
    cout << jumps;
    return jumps[v.size()-1];
}

int main() {
    clock_t tStart = clock();

vector<int> a ={22, 0, 0, 3, 6, 0, 0, 0, 0, 0, 0, 4, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 22, 12, 0, 12, 0, 9, 11, 0, 0, 21, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 23, 0, 19, 0, 19, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 0, 26, 0, 28, 3, 0, 0, 0, 19, 0, 0, 15, 0, 0, 14, 0, 0, 0, 0, 0, 7, 0, 14, 0, 16, 0, 19, 2, 16, 0, 29, 12, 0, 0, 0, 0, 29, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 9, 9, 0, 0, 0, 5, 3, 0, 0, 0, 0, 0, 0, 30, 0, 25, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 20, 30, 29, 0, 23, 17, 0, 0, 20, 0, 0, 0, 3, 17, 10, 0, 0, 0, 0, 0, 0, 15, 0, 0, 6, 0, 0, 0, 0, 0, 11, 2, 27, 0, 22, 0, 8, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 30, 25, 0, 0, 0, 0, 9, 29, 0, 0, 0, 0, 0, 1, 0, 16, 27, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 1, 0, 6, 0, 0, 0, 16, 0, 3, 0, 20, 10, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 3, 0, 17, 0, 0, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 10, 0, 0, 0, 5, 21, 15, 0, 0, 0, 23, 0, 17, 0, 0, 24, 0, 0, 7, 11, 1, 27, 0, 9, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 28, 0, 0, 0, 23, 0, 0, 0, 22, 0, 0, 3, 0, 17, 1, 19, 0, 0, 18, 0, 23, 0, 0, 0, 0, 13, 19, 24, 13, 0, 0, 0, 0, 0, 0, 3, 28, 0, 0, 5, 21, 0, 0, 0, 0, 0, 6, 0, 0, 0, 19, 0, 0, 0, 11, 5, 0, 0, 0, 24, 21, 0, 0, 0, 19, 0, 0, 0, 0, 10, 0, 17, 0, 0, 0, 2, 0, 24, 13, 1, 22, 0, 0, 15, 0, 21, 0, 21, 0, 0, 7, 0, 0, 0, 23, 6, 0, 0, 20, 24, 23, 0, 0, 0, 0, 28, 0, 8, 0, 0, 30, 23, 22, 11, 0, 0, 0, 1, 20, 0, 0, 5, 0, 0, 0, 24, 0, 0, 20, 0, 0, 0, 0, 0, 0, 17, 0, 0, 12, 0, 0, 18, 0, 0, 0, 0, 0, 17, 2, 7, 0, 0, 0, 0, 0, 5, 16, 0, 0, 0, 0, 16, 0, 0, 8, 0, 0, 1, 25, 14, 1, 24, 19, 0, 0, 0, 0, 0, 24, 7, 0, 0, 0, 0, 21, 0, 0, 0, 0, 17, 0, 0, 0, 0, 8, 0, 0, 15, 0, 0, 9, 0, 0, 8, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 13, 20, 0, 26, 0, 0, 0, 2, 0, 28, 0, 0, 0, 0, 0, 11, 0, 27, 0, 0, 10, 19, 0, 0, 0, 0, 13, 25, 30, 28, 28, 0, 21, 0, 0, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 22, 0, 1, 0, 0, 0, 0, 0, 9, 0, 0, 4, 0, 2, 0, 0, 0, 0, 0, 0, 14, 29, 0, 4, 0, 12, 0, 0, 0, 0, 25, 0, 0, 29, 0, 21, 8, 0, 0, 0, 0, 0, 0, 0, 0, 28, 7, 5, 0, 0, 6, 0, 24, 11, 0, 11, 20, 6, 30, 21, 0, 8, 0, 0, 28, 28, 4, 0, 17, 0, 6, 22, 0, 27, 0, 0, 0, 0, 29, 26, 0, 6, 0, 8, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 20, 0, 0, 0, 5, 21, 2, 0, 0, 0, 28, 0, 0, 20, 0, 0, 7, 0, 0, 25, 0, 0};
    cout<<(min_jumps_(a));

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
