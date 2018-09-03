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


int searchMatrix(vector<vector<int> > &A, int B) {
    int start = 0;
    int C = A.size();
    int R = A[0].size();
    int end = R*C-1;
    int mid;
    while(start <= end) {
        int mid = (start + end - 1) / 2;
        if(A[mid/C][mid%C] < B)
            start = mid + 1;
        else
            end = mid;
    }
    return A[mid/C][mid%C] == B;
}


int main() {
    clock_t tStart = clock();

    int R = 5;
    int C = 4;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            int pos = i*C+j;
            cout << i  << j << " " << pos <<"\t\t";
        }
        cout << "\n";
    }

    for(int i = 0; i < 20; i++) {
        if(i%C == 0) cout << "\n";
        cout << i << " " << i/C << i%C << "\t";
    }

    vector<vector<int>> v {
        {3, 3, 11, 12, 14},
        {16, 17, 30, 34, 35},
        {45, 48, 49, 50, 52},
        {56, 59, 63, 63, 65},
        {67, 71, 72, 73, 79},
        {80, 84, 85, 85, 88},
        {88, 91, 92, 93, 94},
        };
    cout << searchMatrix(v, 94);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
