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

int braces(string A) {
    int N = A.size();
    stack<char> Stk;

    for(int i = 0; i < N; ++i) {
        if(A[i] == ')') {
            int cnt = 0;

            while(Stk.top() != '(') {
                Stk.pop();
                cnt++;
            }
            Stk.pop();
            if(cnt < 2)
                return 1;
        }
        else {
            Stk.push(A[i]);
        }
    }
    bool is = true;

    while(Stk.size()) {
        if(Stk.top() == '(' || Stk.top() == ')') {
            is = false;
            break;
        }
        Stk.pop();
    }
    if(!is) return 1;
    return 0;
}

int main() {
    clock_t tStart = clock();

    cout << braces("(a + (a + b))");

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
