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

string add_binary(string A, string B)
{
    int i = A.length() - 1;
    int j = B.length() - 1;
    int carry = 0;
    int sum;
    string ans = "";
    while(i >= 0 || j >=0 || carry) {
        sum = carry;
        if(i >= 0) sum = sum + A[i]-'0';
        if(j >= 0) sum = sum + A[j]-'0';
        ans = ans + char('0' + sum%2);
        carry = sum/2;
        i--, j--;
    }
    reverse(ans);
    return ans;
}

int main() {
    clock_t tStart = clock();

    add_binary(")

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
