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

int merge(int *A, int start, int mid, int end) {
    int temp[end-start+1]; //this array in the end will be sorted from position start to end
    int i = start; // the first half
    int j = mid; // the second half
    int k = 0; // the index to control the temp index
    int count = 0; // to store the inversions
    while(i <= mid-1 && j <= end) {
        if(A[i]<=A[j]) {
            temp[k++] = A[i++]; // insert the element of A in temp
        } else {
            temp[k++] = A[j++];
            count += mid - i;
        }
    }

    // Only one of these while loop will work
    while(i <= mid-1) { // insert remaining elements of A in temp
        temp[k++] = A[i++];
    }
    while(j <= end) { // insert the remaining elements of A in temp
        temp[k++] = A[j++];
    }

    // copy the temp array to A from start to end
    for(int i = start; i <= end; i++) {
        A[i] = temp[i-start];
    }
    return count;
}


// COUNTING INVERSIONS
int merge_sort(int* A, int start, int end) {
    if(start<end) {
        int mid = (start+end)/2;
        return merge_sort(A, start, mid)+
        merge_sort(A, mid+1, end)+
        merge(A, start, mid+1, end);
    } else {
        return 0;
    }
}

int main() {
    clock_t tStart = clock();

    int v[] = {2, 4, 1, 3, 5};
    int sz = 5;
    for(int i= 0 ;i < sz; i++) {
        cout << v[i] << " ";
    }

    cout << "\n";
    cout << merge_sort(v,0, sz - 1) << "\n";
    for(int i= 0 ;i < sz; i++) {
        cout << v[i] << " ";
    }
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
