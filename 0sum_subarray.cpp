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

int maxLen(vector<int> &arr, int n)
{
    // Map to store the previous sums
    vector<int> m{1,2,3};
    map<pair<int, int>, vector<int> > presum;

    pair<int, int> q(1,2);
    presum[q] = m;
    cout << presum;
    //int sum = 0;        // Initialize the sum of elements
    //int max_len = 0;    // Initialize result

    //// Traverse through the given array
    //for(int i=0; i<n; i++)
    //{
        //// Add current element to sum
        //sum += arr[i];

        //if (arr[i]==0 && max_len==0)
            //max_len = 1;
        //if (sum == 0)
            //max_len = i+1;

        //// Look for this sum in Hash table
        //if(presum.find(sum) != presum.end())
        //{
            //// If this sum is seen before, then update max_len
            //max_len = max(max_len, i-presum[sum]);
        //}
        //else
        //{
            //// Else insert this sum with index in hash table
            //presum[sum] = i;
        //}
    //}
    //cout << presum;

    return 0;
}

// Driver Program to test above function
int main()
{
    vector<int> arr {15, -2, 2, -8, 1, 7, 10, 23};
    int n = arr.size();
     cout << maxLen(arr, n);

    return 0;
}
