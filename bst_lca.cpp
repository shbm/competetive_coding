#include <stdio.h>
#include <stdlib.h>
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
    Node(int data): data(data), left(NULL), right(NULL) {}
};

struct Node *newNode(int data) {
    Node *temp = new Node(data);
    return temp;
}

void inorder(struct Node *root) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->data)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

struct Node * minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *lca(Node *root, int x, int y) {
    if(root == NULL) return NULL;

    if(root->data > max(x, y)) {
        return lca(root->left, x, y);
    }
    if(root->data < min(x, y)) {
        return lca(root->right, x, y);
    }
    return root;
}

int main() {
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);

    Node *l = lca(root, 20, 40);
    cout << l->data;

    return 0;
}

