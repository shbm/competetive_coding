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

vector<int> searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start = 0;
    int end = A.size()-1;
    bool f = false;
    vector<int > v;

    while(start <= end) {
        int mid = (start + end)/2;
        cout << "\n" << mid << "\n";
        if(A[mid] == B) {
            cout << "here";
            f = true;
            int s = mid - 1;
            int e = mid + 1;
            while(A[s] == B) {
                s--;
            }
            while(A[e] == B) {
                e++;
            }
            v.push_back(s+1);
            v.push_back(e-1);
            break;
        } else if(A[mid] > B) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    if(f) {
        return v;
    } else {
        return {-1, 1};
    }
}


int main() {
    clock_t tStart = clock();

    vector<int> v {5, 7, 7, 8, 8, 10};
    int B = 8;

    cout << searchRange(v, B);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
