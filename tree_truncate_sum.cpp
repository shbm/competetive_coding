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

void inorder(Node *root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool is_leaf(Node *root) {
    return !root->left && !root->right;
}

void truncate(Node *&root, int k, int sum) {
    if(root == NULL) return;

    sum = sum + root->data;

    truncate(root->left, k, sum);
    truncate(root->right, k , sum);

    if(sum < k && is_leaf(root)) {
        free(root);
        root = NULL;
    }
}

void invert(Node *root) {
    if(root == NULL) {
        return;
    }
    swap(root->left, root->right);
    invert(root->left);
    invert(root->right);
}

int main() {
    clock_t tStart = clock();

    /*
           6
          / \
        /     \
       3       8
              /  \
             4    2
            / \     \
           1   7     3
    */
    Node *root = new_node(6);
    root->left = new_node(3);
    root->right = new_node(8);
    root->right->left = new_node(4);
    root->right->right = new_node(2);
    root->right->right->right = new_node(3);
    root->right->left->left = new_node(1);
    root->right->left->right = new_node(7);

    inorder(root);
    invert(root);
    cout << "\n";
    inorder(root);


    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

