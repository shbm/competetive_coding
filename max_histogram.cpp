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

int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    int ans = 0;
    vector<int> lIdx(n), rIdx(n);
    stack<int> l, r;
    for(int i = 0; i < n; i++) {
        while(!l.empty() && heights[l.top()] > heights[i]) {
            rIdx[l.top()] = i;
            l.pop();
        }
    }
    while(!l.empty()) {
        rIdx[l.top()] = n;
        l.pop();
    }

    for(int i = n-1; i >= 0; i--) {
        while(!r.empty() && heights[r.top()] > heights[i]) {
            lIdx[r.top()] = i;
            r.pop();
        }
    }

    while(!r.empty()) {
        lIdx[r.top()] = -1;
        r.pop();
    }

    for(int i = 0; i < n; i++) {
        ans = max(ans, heights[i]*(rIdx[i]-lIdx[i]-1));
    }

    return ans;
}


int main() {
    clock_t tStart = clock();

    vector<int> v{1};
    cout << largestRectangleArea(v);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
