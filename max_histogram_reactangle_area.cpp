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

int largestRectangleArea(vector<int> &A) {
    int n = A.size();
    vector<int> posLeft(n);
    stack<int> S;
    for (int i = 0; i < n; i++) {
        while (!S.empty() && A[S.top()] >= A[i])
            S.pop();
        posLeft[i] = S.empty() ? 0 : S.top()+1;
        S.push(i);
    }

    cout << A;
    for(int i: posLeft) {
        cout <<" " << i << " ";
    }
    cout <<  "\n";
    vector<int> posRight(n);
    while (!S.empty()) S.pop();
    for (int i = n-1; i >= 0; i--) {
        while (!S.empty() && A[S.top()] >= A[i])
            S.pop();
        posRight[i] = S.empty() ? n-1 : S.top() - 1;
        S.push(i);
    }
    for(int i: posRight) {
        cout <<" " << i << " ";
    }

    cout << "\n";
    int maxArea = 0;
    for (int i = 0; i < n; i++)
        maxArea = max(maxArea, (posRight[i] - posLeft[i] + 1) * A[i]);
    return maxArea;
}
int largestRectangleAreaa(vector<int>& heights) {
    int N = heights.size();
    if (N==0) return 0;

    vector<int> lIdx(N), rIdx(N);
    stack<int> l, r;

    for (int i=0;i<N; i++){
        while (!l.empty() && heights[l.top()]>heights[i]){
            rIdx[l.top()] = i;
            l.pop();
        }
        l.push(i);
    }
    while (l.size()){
        rIdx[l.top()] = N;
        l.pop();
    }

    cout << heights;
    for(int i: rIdx) {
        cout << heights[i] << ", ";
    }
    cout << "\n";
    for (int i=N-1;i>-1; i--){
        while (!r.empty() && heights[r.top()]>heights[i]){
            lIdx[r.top()] = i;
            r.pop();
        }
        r.push(i);
    }
    while (r.size()){
        lIdx[r.top()] = -1;
        r.pop();
    }

    cout << heights;
    for(int i: lIdx) {
        cout << heights[i] << ", ";
    }
    cout << "\n";
    int area = 0;
    for (int i=0;i<N;i++)
        area = max(heights[i]*(rIdx[i]-lIdx[i]-1), area);
    return area;
}

int main() {
    clock_t tStart = clock();

    vector<int> v {90, 58, 69, 70, 82, 100, 13, 57, 47, 18};
    cout << largestRectangleAreaa(v);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
