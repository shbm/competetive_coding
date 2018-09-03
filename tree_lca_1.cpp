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

bool find_lca(Node *root, int n1, int n2, bool &n1_found, bool &n2_found, Node *&lca) {
    if(root == nullptr) {
        return false;
    }
    cout << "find_lca:" << root->data << " ";
    if(lca!=NULL) cout << "LCA: " << lca->data << "\n";

    if(root->data == n1) {
        lca = root;
        n1_found = true;
        lca = root;
        return true;
    }

    if(root->data == n2) {
        lca = root;
        n2_found = true;
        return true;
    }

    bool left = find_lca(root->left, n1, n2, n1_found, n2_found, lca);
    bool right = find_lca(root->right, n1, n2, n1_found, n2_found, lca);

    if(left && right) {
        lca = root;
    }

    cout << "\n---\n";
    cout << "FIND_LCA:" << root->data << " ";
    if(lca!=NULL) cout << "LCA: " << lca->data << "\n";
    return left || right;
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

    cout << ".";
    Node *lca = NULL;
    int n1 = 6, n2 = 8;
    bool n1_found = 0, n2_found = 0;
    if(find_lca(root, n1, n2, n1_found, n2_found, lca) && n1_found && n2_found) cout << " " << lca->data;

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
