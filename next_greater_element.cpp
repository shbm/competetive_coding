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
#include <stack>
#include <time.h>
#include <climits>

using namespace std;

int main() {
    clock_t tStart = clock();

    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(int);

    stack<int> s;

    for(int i = 0; i < n; i++) {
        int next = arr[i];

        if(!s.empty()) {
            int element = s.top();
            s.pop();

            while(element < next) {
                cout << "\n" << element << " -> " << next << "\n";
                if(s.empty()) break;
                element = s.top();
                s.pop();
            }

            if(element > next) {
                s.push(element);
            }
        }

        s.push(next);
    }

    while(!s.empty()) {
        cout << "\n" << s.top() << " -> -1" << "\n";
        s.pop();
    }

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
