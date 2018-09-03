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
    inorder(root->right);
    cout << root->data << " ";
}

void extract_keys(Node *root, set<int> &s) {
    if(root == NULL) {
        return;
    }
    extract_keys(root->left, s);
    s.insert(root->data);
    extract_keys(root->right, s);
}

void convert_to_BST(Node *root, set<int>::iterator &it) {
    if(root == NULL) return;
    convert_to_BST(root->left, it);
    root->data = *it;
    it++;
    convert_to_BST(root->right, it);
}

int sum = 0;
int leaf_sum(Node *root, int curr) {
    if(!root) {
        return 0;
    }
    int sum = curr*10+root->data;

    if(!root->left && !root->right) {
        return sum;
    }

    return leaf_sum(root->left, sum) + leaf_sum(root->right, sum);
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

    //set<int> s;
    //extract_keys(root, s);
    //set<int>::iterator it = s.begin();
    //convert_to_BST(root, it);
    //inorder(root);
    //
    cout << leaf_sum(root, 0);
    cout << "\n" << sum;


    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
