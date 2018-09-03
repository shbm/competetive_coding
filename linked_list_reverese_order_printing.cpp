#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <unordered_map>
#include <time.h>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data): data(data), next(nullptr) {}
};
void insert_front(Node *&root, int data) {
    cout << " .";
    Node *n = new Node(data);
    n->next = root;
    root = n;
}

void reverse_linked_list(Node *r, Node *&root) {
    if(r == NULL) return;
    insert_front(root, r->data);
    reverse_linked_list(r->next, root);
}

void print_list(Node *root) {
    if(root == NULL) return;
    cout << root->data << " ";
    print_list(root->next);
}

int main() {
    clock_t tStart = clock();

    Node *r = NULL;
    cout << '.';
    for(int i = 0; i < 10; i++) {
        insert_front(r, i);
    }
    print_list(r);
    Node *reverse_ll = NULL;
    reverse_linked_list(r, reverse_ll);
    print_list(reverse_ll);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
