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

template <typename T>
ostream& operator<<(ostream& os, const set<T>& v)
{
    os << "[";
    for (auto it : v) {
        os << it;
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "]\n";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v)
{
    os << "(";
    os << v.first << ", "
        << v.second << ")";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v)
{
    for (auto it : v)
        os << it.first << " : "
            << it.second << "\n";

    return os;
}

set<string> s;

bool id_exists(string str) {
    if(s.find(str) != s.end()) {
        return 1;
    } else {
        return 0;
    }
}

void indent(int k) {
    for(int i = 0; i < k; i++) {
        cout << "    ";
    }
}

int word_break_bottom_up(string str) {
    //vector<vector<int>> dp(str.length(), vector<int> (str.length(), -1));
    int len = str.length();
    int dp[len][len];

    for(int l = 1; l <= len; l++) {
        for(int i = 0; i < len - l + 1; i++) {
            int j = i + l - 1;

            string temp = str.substr(i, j);
            cout << temp << "\n";
            if(s.find(temp) != s.end()) {
                dp[i][j] = i;
                continue;
            }
            for(int k = i+1; k <= j; k++) {
                if(dp[i][k-1] != -1 && dp[k][j] != -1) {
                    dp[i][j] = k;
                    break;
                }
            }
        }
    }

    return dp[0][len-1];
}

int word_break(string A) {
    cout << "word_break(\"" << A << "\")" << "\n";
    int size = A.length();

    if(size == 0) {
        return 1;
    }
    for(int i = 1; i <= size; i++) {
        if(id_exists(A.substr(0, i)) && word_break(A.substr(i, size - i))) {
            return 1;
        }
    }
    return 0;
}

int main() {
    clock_t tStart = clock();

    string str = "myinterviewtrainer";
    vector<string> V{"trainer", "my", "interview"};

    for(string i: V)
        s.insert(i);
    cout <<s;
    cout << word_break_bottom_up(str);



    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
