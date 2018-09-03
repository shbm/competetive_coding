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

Node *new_node(int data){
    Node *n = new Node(data);
    return n;
}

void inorder(Node *root) {
    if(root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void insert(Node *&root, int data) {
    if(root == nullptr) {
        root = new_node(data);
        return;
    }
    if(data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

int main() {
    clock_t tStart = clock();

    Node *root = nullptr;
    int k[] = {7,6,5,4,3,2,1};

    for(int i = 0; i < 7; i++) {
        insert(root, k[i]);
    }
    inorder(root);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
