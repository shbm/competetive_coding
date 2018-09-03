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

vector<int> sliding_window_max(vector<int> const &A, int window) {
    vector<int> sol;
    deque<int> d;

    for(int i = 0; i < window; i++) {
        while(!d.empty() && A[i] >= A[d.back()]) {
            d.pop_back();
        }
        d.push_back(i);
    }

    for(int i = window; i < A.size(); i++) {
        if(!d.empty())
            sol.push_back(d.front());

        while(!d.empty() && A[i] >= A[d.back()]) {
            d.pop_back();
        }
        while(!d.empty() && d.front() <= i - window) {
            d.pop_front();
        }

        d.push_back(i);
    }
    sol.push_back(d.front());
    return sol;
}

int main() {
    clock_t tStart = clock();

    vector<int> s = {1, 3, -1, -3, 5, 3, 6, 7};
    int  window  = 3;
    for(int i: sliding_window_max(s, window)) {
        cout << s[i] << " ";
    }

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
