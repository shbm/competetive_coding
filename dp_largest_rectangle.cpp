#include <stdio.h>
#include <queue>
#include <sstream>
#include <istream>
#include <iostream>
#include <iterator>
#include <cstring>
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

bool cmp(int a, int b) {
    return a>b;
}

int solve(vector<vector<int> > &A) {
    if(!A[0].size()) {
        return 0;
    }
    int R = A.size();
    int C = A[0].size();

    vector<vector<int> > aux(R, vector<int>(C, 0));

    for(int i = 0; i < C; i++) {
        aux[0][i] = A[0][i];
        for(int j = 1; j < R; j++) {
            aux[j][i] = A[j][i] == 0 ? 0 : aux[j-1][i]+1;
        }
    }
    cout << aux;

    for(int i = 0; i < R; i++) {
        sort(aux[i].begin(), aux[i].end(), cmp);
    }
    cout << aux;
    int ans = INT_MIN;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            ans = max(ans, (j+1)*aux[i][j]);
        }
    }
    return ans;
}


struct Node {
    int count;
    bool end;
    Node *child[26];
}*head;

void init() {
    head=new Node();
    head->count = 0;
    head->end = false;
}

void insert(string s) {
    Node *curr = head;
    curr->count++;
    for(char i:s) {
        int letter = (int)(i-'a');
        if(!curr->child[letter]) {
            curr->child[letter] = new Node();
        }
        curr->child[letter]->count++;
        curr = curr->child[letter];
    }
    curr->end = true;
}

int main() {
    clock_t tStart = clock();

    vector<vector<int> > v
    {
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 1, 0}
    };
    //cout << solve(v);
    init();
    string s = "shubham_stibaysab_dgs";
    istringstream A(s);
    string str;
    while(getline(A, str, '_')) {
        insert(str);
        cout << str << "\n";
    }

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
