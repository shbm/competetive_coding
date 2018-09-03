// TREE STRUCUTRE
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
    Node *left, *right;
    Node (int data): data(data), left(nullptr), right(nullptr) {}
};

Node *new_node(int data) {
    return new Node(data);
}

void swap(Node *&a, Node *& b) {
    Node *temp = a;
    a = b;
    b = a;
}

void inorder(Node *root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void sink_down(Node *root) {
    if(root == NULL) return;

    if(root->left && root->left->data != 0) {
        swap(root->data, root->left->data);
        sink_down(root->left);
    } else if(root->right && root->right->data != 0) {
        swap(root->data, root->right->data);
        sink_down(root->right);
    }
}

void sink_nodes(Node *root) {
    if(root == NULL) return;

    sink_nodes(root->left);
    sink_nodes(root->right);

    if(root->data == 0) {
        sink_down(root);
    }
}

int main() {
    clock_t tStart = clock();

    /*
           1
          / \
        /     \
       2       3
        \     /  \
         4   5    6
            / \
           7   8
    */
    Node *root = new_node(0);
    root->left = new_node(0);
    root->right = new_node(0);
    root->left->right = new_node(4);
    root->right->left = new_node(0);
    root->right->right = new_node(6);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(8);

    inorder(root);
    sink_nodes(root);
    inorder(root);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
