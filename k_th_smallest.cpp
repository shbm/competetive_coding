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

    vector<int> v {2, 1, 4, 3, 2};
    int k = 3;

    int t;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i < v.size(); i++) {
        pq.push(v[i]);
    }
    for(int i = 0; i < k; i++) {
        t = pq.top();
        pq.pop();
    }
    cout << t;
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
