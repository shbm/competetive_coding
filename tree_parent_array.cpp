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

void leaf_to_path(vector<int> &v, Node *root) {
    if(root == NULL) {
        return;
    }
    v.push_back(root->data);

    if(root->left == NULL && root->right == NULL) {
        for(auto i : v)
            cout << i << " ";
        cout << "\n";
    }

    leaf_to_path(v, root->left);
    leaf_to_path(v, root->right);

    v.pop_back();
}

Node *create_tree(int parent[], int n) {
    unordered_map<int, Node *> map;
    for(int i = 0; i < n; i++) {
        map[i] = new_node(i);
    }
    Node *root = nullptr;

    for(int i = 0; i < n; i++) {
        if(parent[i] == -1) {
            root = map[i];
        } else {
            Node *ptr = map[parent[i]];

            if(ptr->left) {
                ptr->right = map[i];
            } else {
                ptr->left = map[i];
            }
        }
    }
    return root;
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

    int a[] = {-1, 0, 0, 1, 2, 2, 4, 4};
    Node *r = create_tree(a, sizeof(a)/sizeof(int));
    //inorder(r);
    vector<int> v;
    leaf_to_path(v, root);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

