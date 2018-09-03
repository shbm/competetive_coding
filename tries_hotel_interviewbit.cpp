#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
    bool end;
    int count;
    node *child[26];
}*head;

void init() {
    head = new node();
    head->end = false;
    head->count = 0;
}

void insert(string s) {
    node *current = head;
    current->count++;
    for(char i:s) {
        int letter = (int)(i-'a');
        if(!current->child[letter]) {
            current->child[letter] = new node();
        }
        current->child[letter]->count++;
        current = current->child[letter];
    }
    current->end = 1;
}

string unique_prefix(string s) {
    node* curr = head;
    string k = "";
    for(char i : s) {
        k += i;
        int letter = (int)(i-'a');
        if(curr->child[letter]->count == 1) {
            return k;
        }
        curr = curr->child[letter];
    }
    return k;
}

int main() {
    init();
    vector<string> v{"zebra", "dog", "duck", "dove"};
    for(string i : v) {
        insert(i); 
    }
    vector<string> ans;
    for(string i: v) {
        ans.push_back(unique_prefix(i));
    }
    for(string i:ans) {
        cout << i << " ";
    }
}