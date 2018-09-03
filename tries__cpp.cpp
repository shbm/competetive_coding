#include <iostream>
#include <string>

using namespace std;

struct node {
    bool is_end;
    int count;
    node* child[26];
}*head;

void init() {
    head = new node();
    head->is_end = false;
    head->count = 0;
}

void insert(string s) {
    node* curr = head;
    curr->count++;
    for(char i:s) {
        int letter = (int)(i-'a');
        if(!curr->child[letter]) {
            curr->child[letter] = new node();
        }
        curr->child[letter]->count++;
        curr = curr->child[letter];
    }
    curr->is_end = true;
}

bool search(string s) {
    node *curr = head;
    for(char i: s) {
        int letter = (int)(i-'a');
        if(!curr->child[letter]){
            return false;
        }
        curr = curr->child[letter];
    }
    return curr->is_end;
}

int prefix_count(string s) {
    node *curr = head;
    for(char i: s) {
        int letter = (int)(i-'a');
        if(!curr->child[letter]) {
            return 0;
        }
        curr = curr->child[letter];
    }
    return curr->count;
}

int main() {
    init();
    insert("shubham");
    insert("shivam");
    cout << search("shubham") << "\n";
    cout << prefix_count("sh");
    return 1;
}