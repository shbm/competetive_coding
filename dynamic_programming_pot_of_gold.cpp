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

int optimal_gaming_strategy(int coins[], int i, int j) {
    if(i == j) {
        return coins[i];
    }
    if(i + 1 == j) {
        return max(coins[i], coins[j]);
    }

    int a = coins[i] + min(optimal_gaming_strategy(coins, i+2, j),
                           optimal_gaming_strategy(coins, i+1, j-1));
    int b = coins[j] + min(optimal_gaming_strategy(coins, i+1, j-1),
                           optimal_gaming_strategy(coins, i, j-2));

    return max(a, b);
}

int main() {
    clock_t tStart = clock();

    
    int coin[] = { 4, 6, 2, 3 };
    cout << optimal_gaming_strategy(coin, 0, 3);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
