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

int IDX;
vector<vector<int> > Cnt;
vector<vector<int> > Trie;

void insert(string str)
{
    int len = str.size();
    int root = 0;
    int i = 0;

    while(i < len) {
        int chr = str[i] - 'a';
        if(Trie[root][chr] == -1) {
            ++IDX;
            Trie[root][chr] = IDX;
            Cnt[root][chr] = 1;
        } else {
            Cnt[root][chr]++;
        }
        root = Trie[root][chr];
        i++;
    }
}

string Query(string str)
{
    int root = 0;
    string ans = "";
    int i = 0;
    int len = str.size();

    while(i < len) {
        int chr = str[i] - 'a';
        ans += str[i];
        if(Cnt[root][chr] == 1)
            return ans;
        root = Trie[root][chr];
        i++;
    }
    return "";
}

vector<string> prefix(vector<string> Vec)
{
    int mx_len = 0;
    int N = Vec.size();
    for(int i = 0; i < N; ++i) {
        mx_len = max(mx_len, (int)Vec[i].size());
    }

    Trie.clear();
    Cnt.clear();
    Trie.resize(N * mx_len + 1, vector<int>(27, -1));
    Cnt.resize(N * mx_len + 1, vector<int>(27, -1));
    IDX = 0;

    for(int i = 0; i < N; ++i) {
        insert(Vec[i]);
    }

    cout<<Trie;
    vector<string> Ans;
    for(int i = 0; i < N; ++i) {
        string ans = Query(Vec[i]);
        Ans.push_back(ans);
    }

    return Ans;
}


int main() {
    clock_t tStart = clock();
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    vector<string> v{"zebra", "dog", "duck", "dove"};
    cout << prefix(v);

    return 0;
}
