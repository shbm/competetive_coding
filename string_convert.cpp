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

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

string convert(string A, int B) {
    int n = A.length();
    if(B == 1) return A;
    vector<int> pos(n);
    int dir = -1;
    int p = 0;
    vector<string> s(B, "");
    for(int i = 0; i < n; i++) {
        pos[i] = p;
        s[p] = s[p] + A[i];
        if(dir == -1) {
            p++;
        }
        if(dir == 1) {
            p--;
        }
        if(p == 0) {
            dir = -1*dir;
        }
        if(p == B-1) {
            dir = -1*dir;
        }
    }
    string ans = "";
    for(string c: s) {
        ans += c;
    }
    return ans;
}


int main() {
    clock_t tStart = clock();

    convert("PAYPALISHIRING", 1);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
