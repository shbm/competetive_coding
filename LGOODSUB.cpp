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

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int m = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(v[i]>=v[j] && j-i+1>m) {
                    m = j-i+1;
                }
            }
        }
        cout << m << "\n";
    }

    return 0;
}
