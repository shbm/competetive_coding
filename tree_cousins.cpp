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

struct ParentInfo {
    int key;
    int level;
    Node *parent;
};

Node *new_node(int data) {
    return new Node(data);
}

void cousins(Node *root, ParentInfo &x, ParentInfo &y, Node *parent, int level) {
    if(root == NULL) return;

    cousins(root->left, x, y, root, level+1);
    if(x.key == root->data) {
        x.level = level;
        x.parent = parent;
    }
    if(y.key == root->data) {
        y.level = level;
        y.parent = parent;
    }
    cousins(root->right, x, y, root, level+1);
}

bool is_cousin(Node *root, int a, int b){
    if(root == NULL) return false;
    int level = 1;
    ParentInfo x = {a, level, nullptr};
    ParentInfo y = {b, level, nullptr};
    cousins(root, x, y, NULL, level);
    if(x.level == y.level && x.parent != y.parent) {
        return true;
    }
    return false;
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
    cout << is_cousin(root,2,3);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
