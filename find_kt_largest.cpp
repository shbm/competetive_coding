#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

int find_kth_largest(vector<int> A, int k) {
    priority_queue<int, vector<int>, less<int> > pq(A.begin(), A.begin() + k);

    cout << pq.top() << " ";
    int n = A.size();

    for(int i = k; i < n; i++) {
        if(A[i] > pq.top()) {
            pq.pop();
            pq.push(A[i]);
        }
    }
    return pq.top();
}

int main() {

    vector<int> A;
    for(int i = 0; i < 10; i++) {
        A.push_back(i);
    }
    A.push_back(-1);
    int k = 4;
    cout << find_kth_largest(A, k);
    return 0;
}
