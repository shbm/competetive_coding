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

int k_smallest(Node *root, int k, int &i, string s) {
    if(root != NULL)
        cout << root->data << " " << k << " " << i << " "<< s << "===\n";


    if(root == NULL) return INT_MIN;

    int left = k_smallest(root->left, k, i, "left");
    if(left != INT_MIN) {
        cout << "__\n";
        return left;
    }
    if(++i == k) {
        return root->data;
    }
    return k_smallest(root->right, k, i, "right");
}

int k_largest(Node *root, int k, int &i) {
    if(root == NULL) {
        return INT_MIN;
    }
    int right = k_largest(root->right, k, i);
    if(right != INT_MIN) {
        return right;
    }
    if(++i == k) {
        return root->data;
    }
    return k_largest(root->left, k, i);
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

    int i = 0;
    cout << k_largest(root, 3, i);

    return 0;
}

