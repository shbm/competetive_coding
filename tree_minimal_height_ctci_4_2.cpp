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
    Node *left;
    Node *right;
    Node(int x): data(x), left(nullptr), right(nullptr) {}
};

Node *new_node(int data) {
    return new Node(data);
}

void insert(Node *&root, int data) {
    if(root == nullptr) {
        root = new_node(data);
        return;
    }
    if(data > root->data) {
        insert(root->right, data);
    } else {
        insert(root->left, data);
    }
}

void inorder(Node *r) {
    if(r == nullptr) {
        return;
    }
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void create_minimal_height_tree(Node *&root, int a[], int low, int high) {
    if(low > high) return;
    int mid = (low+high)/2;
    root = new_node(a[mid]);
    create_minimal_height_tree(root->left, a, low, mid - 1);
    create_minimal_height_tree(root->right, a, mid + 1, high);
}

int main() {
    clock_t tStart = clock();
    int a[] = {1111,2,3,4,5,6,7,8};
    Node *r = nullptr;
    int l = sizeof(a)/sizeof(int);
    sort(a, a+l);
    create_minimal_height_tree(r, a, 0, l-1);
    inorder(r);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
