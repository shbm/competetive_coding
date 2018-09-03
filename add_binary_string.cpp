#include <stdio.h>
#include <stdlib.h>
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

    string A = "100101";
    string B = "010";
    cout << "\n" << A << "\n";
    cout << "\n" << B << "\n";
    int len_a = A.length();
    int len_b = B.length();
    int l;

    if(len_a > len_b) {
        int pad_len = len_a - len_b;
        for(int i = 0; i < pad_len; i++) {
            B = "0" + B;
        }
        l = len_a;
    }
    else {
        int pad_len = len_a - len_b;

        for(int i = 0; i < pad_len; i++) {
            A = "0" + A;
        }

        l = len_b;
    }
    cout << "\n" << A << "\n";
    cout << "\n" << B << "\n";

    int carry = 0;
    string s = "";
    cout << stoi(A[0].c_str());
    //for(int i = l-1; i <= 0; i--) {
        //int c = stoi(carry);
        //int a = stoi(A[i]);
        //int b = stoi(B[i]);
        //int d = a + b + carry;
        //if(d == 0) {
            //d = 0;
            //carry = 0;
        //}
        //if(d == 1) {
            //d = 1;
            //carry = 0;
        //}
        //if(d == 2) {
            //d = 0;
            //carry = 1;
        //}
        //if(d == 3) {
            //d = 1;
            //carry = 1;
        //}
        //s = to_string(d) + s;
    //}

    s = to_string(carry) + s;
    cout << s;
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
