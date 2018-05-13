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
#include <climits>
#include <time.h>

using namespace std;

int cutrod(int arr[], int n) {
    if(n <= 0) return 0;
    int max_price = INT_MIN;
    for(int i = 0; i < n; i ++) {
        max_price = max(max_price, arr[i] + cutrod(arr, n - i - 1));
    }
    return max_price;
}

int main() {
    clock_t tStart = clock();

    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutrod(arr, sizeof(arr)/sizeof(int));

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
