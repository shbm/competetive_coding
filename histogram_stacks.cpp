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

int max_area(vector<int> &histogram) {
    stack<int> s;
    int max_area = INT_MIN;
    int area = INT_MIN;
    int i = 0;
    for(i = 0; i < histogram.size();) {
        if(s.empty() || histogram[s.top()] <= histogram[i]) {
            s.push(i++);
        } else {
            int top = s.top();
            s.pop();
            if(s.empty()) {
                area = histogram[top] * i;
            } else {
                area = histogram[top] * (i-s.top()-1);
            }
        }
        max_area = max(area, max_area);
    }
    while(s.size()) {
        int top = s.top();
        s.pop();

        if(s.empty()) {
            area = histogram[top] * i;
        } else {
            area = histogram[top] * (i-s.top()-1);
        }
        max_area = max(area, max_area);
    }
    return max_area;
}

int max_1_area(vector<vector<int>> v) {
    vector<int> temp(v[0].size(), 0);

    int area = INT_MIN;
    int max_a = INT_MIN;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            if(v[i][j] == 0) {
                temp[j] = 0;
            } else {
                temp[j] += v[i][j];
            }
        }
        max_a = max(max_area(temp), max_a);
    }
    return max_a;
}

int main() {
    clock_t tStart = clock();

    vector<vector<int> > r{{1,1,1,0},
                         {1,1,1,1},
                         {0,1,1,0},
                         {0,1,1,1},
                         {1,0,0,1},
                         {1,1,1,1}};

    vector<int> v{2,1,2,3,1};
    cout << max_1_area(r);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
