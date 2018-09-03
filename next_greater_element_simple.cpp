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
#include <climits>

using namespace std;

int main() {
    clock_t tStart = clock();

    stack<int> s;
    int a[] = { 98, 23, 54, 12, 20, 7, 27 };

    int n = sizeof(a)/sizeof(int);

    s.push(a[0]);

    for(int i = 0; i < n; i++) {
        while(!s.empty() && s.top() < a[i]) {
            cout << "NGE for" << s.top() << " " << a[i] << "\n";
            s.pop();
        }
        s.push(a[i]);
    }
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
