#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <time.h>
#include <climits>

using namespace std;

int repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    float n = A.size();
    int candidate1, candidate2;
    //for(int i: A) {
        //if(count1 == 0) {
            //candidate1 = i;
            //count1++;
        //} else if(count2 == 0) {
            //candidate2 = i;
            //count2++;
        //} else if(candidate1 == i) {
            //count1++;
        //} else if(candidate2 == i) {
            //count2++;
        //} else {
            //count1--;
            //count2--;
        //}
    //}



    int count1 = 0, count2 = 0;
    int first=INT_MAX    , second=INT_MAX    ;

    for (int i: A) {

        // if this element is previously seen,
        // increment count1.
        if (first == i)
            count1++;

        // if this element is previously seen,
        // increment count2.
        else if (second == i)
            count2++;

        else if (count1 == 0) {
            count1++;
            first = i;
        }

        else if (count2 == 0) {
            count2++;
            second = i;
        }

        // if current element is different from
        // both the previously seen variables,
        // decrement both the counts.
        else {
            count1--;
            count2--;
        }
    }

    candidate1 = first;
    candidate1 = second;

    cout << candidate1 << " " << candidate2;
    count1 = 0;
    count2 = 0;

    for(int i: A) {
        if(i == candidate1) count1++;
        if(i == candidate2) count2++;
    }
    if(count1 >= n/3) return candidate1;
    if(count2 >= n/3) return candidate2;
    return -1;
}

void plusOne(vector<int> &A) {
    int carry = 0;
    int sum = 0;
    int ans = 0;
    vector<int> sol;

    sum = A[A.size()-1] + 1;
    carry = sum > 9 ? 1 : 0;
    ans = sum%10;

    sol.push_back(ans);

    for(int i = A.size()-2; i >= 0; i--) {
        sum = A[i] + carry;
        carry = sum > 9 ? 1 : 0;
        ans = sum%10;
        sol.push_back(ans);
    }

    if(carry == 1) {
        sol.push_back(1);
    }

    for(int i = sol.size() -1; i>=0; i--)
        cout << sol[i] << " ";
    cout << "\n";
    for(int i: sol) {
        cout << i << " ";
    }
}


int main() {
    clock_t tStart = clock();

    vector<int> v{0};

    plusOne(v);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
