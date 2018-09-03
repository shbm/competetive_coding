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

int isPalindrome(string A) {
    int start = 0;
    int end = A.length()-1;
    while(start <= end) {

        char a = A[start];
        if(a >= 'a' && a <= 'z') {
            a = a-32;
        } if((a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
            a = a;
        } else {
            start++;
            continue;
        }
        
        char b = A[end];
        if(b >= 'a' && b <= 'z') {
            b = b-32;
        } if((b >= 'A' && b <= 'Z') || (b >= '0' && b <= '9')) {
            b = b;
        } else {
            end--;
            continue;
        }
        if(a != b) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    clock_t tStart = clock();

    string s = "A man, a plan, a canal: Panama";
    s = "1a2";
    cout << isPalindrome(s);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
