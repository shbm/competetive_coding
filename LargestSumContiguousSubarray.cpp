#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <climits>


using namespace std;

int longest_sum(vector<int> &A) {
    int max = INT_MIN;
    int max_here = 0;
    for (auto i : A) {
        max_here = max_here + i;
        if(max_here > max) {
            max = max_here;
        }
        if(max_here < 0) {
            max_here = 0;
        }
    }
    return max;
}

int main() {

    vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3};
    cout << longest_sum(v);
    return 0;
}
