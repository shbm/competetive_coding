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


int main() {
    clock_t tStart = clock();

    int num = 14;
    int rman[] = {1000,900,500,400,100,  90,  50, 40,  10, 9,   5,  4,   1};
    string sman[] = {"M","CM","D","CD","C","XC", "L","XL","X","IX","V","IV","I"};

    string ret;
    for(int i = 0; i < 13; i++) {
        int j = num/rman[i];
        num = num-rman[i]*j;
        for(int m = 0; m < j; m++) {
            ret = ret + sman[i];
        }
    }
    cout << ret;

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
