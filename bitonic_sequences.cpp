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

//int len(const vector<int> &A) {
    //int n = A.size();
    //vector<int> inc(n);
    //vector<int> dec(n);
    //int ct = 0;

    //inc[0] = 1;
    //for(int i=1; i<n; i++)
    //{
        //inc[i] = 1;
        //for(int j=i-1; j>=0; j--)
        //{
            //if(A[i] > A[j] && inc[i] < inc[j] + 1)
                //inc[i] = inc[j] + 1;
        //}
    //}

    //dec[n-1] = 1;
    //for(int i=n-2; i>=0; i--)
    //{
        //dec[i] = 1;
        //for(int j=i+1; j<n; j++)
        //{
            //if(A[i] > A[j] && dec[i] < dec[j] + 1)
                //dec[i] = dec[j] + 1;
        //}
    //}

    //cout << A;
    //cout << inc;
    //cout << dec;
    //int mx = 0;
    //for(int i=0; i<n; i++)
        //mx = max(mx, inc[i] + dec[i] - 1);

    //return mx;
//}

//int main() {
    //clock_t tStart = clock();

    //vector<int> A{1, 9, 2, 8, 4, 5, 2, 1};
    //cout << len(A);

    //printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    //return 0;
//}
//

/* Dynamic Programming implementation of longest bitonic subsequence problem */
#include<stdio.h>
#include<stdlib.h>
 
/* lbs() returns the length of the Longest Bitonic Subsequence in
    arr[] of size n. The function mainly creates two temporary arrays
    lis[] and lds[] and returns the maximum lis[i] + lds[i] - 1.
 
    lis[i] ==> Longest Increasing subsequence ending with arr[i]
    lds[i] ==> Longest decreasing subsequence starting with arr[i]
*/
int lbs( vector<int> arr, int n )
{
   int i, j;
 
   /* Allocate memory for LIS[] and initialize LIS values as 1 for
      all indexes */
   vector<int> lis(n, 1);
 
   /* Compute LIS values from left to right */
   for (i = 1; i < n; i++)
      for (j = 0; j < i; j++)
         if (arr[i] > arr[j])
            lis[i] = max(lis[j] + 1, lis[i]);
 
   /* Allocate memory for lds and initialize LDS values for
      all indexes */
   vector<int> lds(n, 1);
 
   /* Compute LDS values from right to left */
   for (i = n-2; i >= 0; i--)
      for (j = n-1; j > i; j--)
         if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
            lds[i] = lds[j] + 1;
 
 
   /* Return the maximum value of lis[i] + lds[i] - 1*/
   int max = lis[0] + lds[0] - 1;
   for (i = 1; i < n; i++)
     if (lis[i] + lds[i] - 1 > max)
         max = lis[i] + lds[i] - 1;
   cout << lis;
   cout << lds;
   return max;
}
 
/* Driver program to test above function */
int main()
{
  vector<int> arr{1,3,5};
  int n = arr.size();
  printf("Length of LBS is %d\n", lbs( arr, n ) );
  return 0;
}
