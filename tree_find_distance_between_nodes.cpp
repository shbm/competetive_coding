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

int find_level(Node *root, int key, int level) {
    if(root == NULL) return INT_MIN;

    if(root->data == key) {
        return level;
    }

    int left = find_level(root->left, key, level+1);

    if(left != INT_MIN) {
        return left;
    }

    return find_level(root->right, key, level+1);
}

bool find_lca(Node *root, int a, int b, Node *&lca) {
    if(root == NULL) {
        return false;
    }

    if(root->data == a || root->data == b) {
        lca = root;
        return true;
    }
    bool left = find_lca(root->left, a, b, lca);
    bool right = find_lca(root->right, a, b, lca);
    if(right && left) {
        lca = root;
    }

    return left || right;
}

int distance(Node *root, int a, int b) {
    Node *lca = nullptr;
    find_lca(root, a, b, lca);
    return find_level(lca, a, 0) + find_level(lca, b, 0);
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
    Node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->right = new_node(4);
    root->right->left = new_node(5);
    root->right->right = new_node(6);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(8);
    cout << find_level(root, 5, 0);
    Node *lca = nullptr;
    cout << "\n";
    find_lca(root, 4, 2, lca);
    cout << lca->data;
    cout << distance(root, 4, 0);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

