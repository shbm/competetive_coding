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

struct node {
    bool is_end;
    int prefix_count;
    struct node* child[26];
};

node* init() {
    node* head = new node();
    head->is_end = false;
    head->prefix_count = 0;
    return head;
}

void insert(string s, node *head) {
    node *current = head;
    current->prefix_count++;
    for(char i: s) {
        int letter = (int)(i-'a');
        if(!current->child[letter]) {
            current->child[letter] = new node();
        }
        current->child[letter]->prefix_count++;
        current = current->child[letter];
    }
    current->is_end = 1;
}

bool search(string s, node *head) {
    node *current = head;
    for(char i: s) {
        int letter = (int)(i-'a');
        if(current->child[letter] == NULL) {
            return false;
        }
        current = current->child[letter];
    }
    return current->is_end;
}

int prefix(string s, node *head) {
    node *current = head;
    for(char i:s) {
        int letter = (int)(i-'a');
        if(!current->child[letter]) {
            return 0;
        }
        current = current->child[letter];
    }
    return current->prefix_count;
}

int main() {
    clock_t tStart = clock();
    node *head = init();
    vector<string> s{"shubham", "shivam", "shivendra", "simran", "abhishek", "abhinav"};
    init();
    for(auto i:s){
        insert(i, head);
    }
    cout << search("shubhami", head);
    cout << prefix("sh", head);
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
