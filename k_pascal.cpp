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

void getRow(int A) {
    int a = 1;
    cout << a << " ";
    for(int i=1; i <= A; i++){
        a = (a * (A-i+1) / i);
        cout<<a<<" ";
    }
}

int main() {
    clock_t tStart = clock();

    getRow(10);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

