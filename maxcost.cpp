#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <unordered_map>
#include <time.h>

using namespace std;

int cost[2000];

map<pair<int, int>, int> cache;

int max_profit( int left, int right) {
    if(cache.find(make_pair(left, right)) != cache.end()) return cache[make_pair(left, right)];
    int year = 4 - right - left;
    if(right < left ) {
        return 0;
    }
    int l = cost[left]*year + max_profit(left+1, right),
        r = cost[right]*year + max_profit(left, right-1);
    int ans = max(l, r);
    cache[make_pair(left, right)] = ans;
    return ans;
}

int main() {
    clock_t tStart = clock();
    /*
    Input2:
    4
    10
    1
    10
    9
    Output:
    79
    */
    cost[0] = cost[2]= 10; cost[3] = 9; cost[1] = 1;
    cout << max_profit(0, 3);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
