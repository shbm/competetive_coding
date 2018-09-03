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

int is_same_bst(int x[], int y[], int n) {
    int leftX[n-1], rightX[n-1], leftY[n-1], rightY[n-1];
    int k = 0, l = 0, m = 0, o = 0;

    if(n == 0) return 1;
    if(x[0] != y[0]) return 0;
    if(n == 1) return 1;

    for(int i = 1; i < n; i++) {
        if(x[i] < x[0]) {
            leftX[k++] = x[i];
        } else {
            rightX[l++] = x[i];
        }
        if(y[i] < y[0]) {
            leftY[m++] = y[i];
        } else {
            rightY[o++] = y[i];
        }
    }
    if(k != m)
        return 0;
    if(l != o)
        return 0;
    return is_same_bst(leftX, leftY, k) && is_same_bst(rightX, rightY, l);
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

    int X[] = { 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6 };
    int Y[] = { 15, 10, 12, 8, 25, 30, 6, 20, 18, 9, 22 };

    int n = sizeof(X) / sizeof(X[0]);
    int m = sizeof(Y) / sizeof(Y[0]);
    cout << is_same_bst(X, Y, n);

    return 0;
}
