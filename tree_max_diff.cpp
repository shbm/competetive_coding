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

int max_diff(Node *root, int &diff) {
    if(root == NULL) return INT_MAX;

    int left = max_diff(root->left, diff);
    int right = max_diff(root->right, diff);

    int d = root->data - min(right, left);

    diff = max(d, diff);
    cout << "diffi: " << diff << "\n";
    return min(min(left, right), root->data);
}

int maxDifference(Node* root, int &diff)
{
    // base case: if tree is empty, return infinity
    if (root == nullptr)
        return INT_MAX;

    // recurse for left and right subtree
    int left = maxDifference(root->left, diff);
    int right = maxDifference(root->right, diff);

    // find maximum difference between current node and its descendants
    int d = root->data - min(left, right);

    // update the maximum difference found so far if required
    diff = max(diff, d);

    // in order for difference to be maximum, the function should return
    // minimum value among all nodes in sub-tree rooted at it
    return min(min(left, right), root->data);
}

int dosomething(Node *ptr) {
    int value = 0;
    if(ptr != NULL) {
        if(ptr->left != NULL) {
            value = 1 + dosomething(ptr->left);
        }
        if(ptr->right != NULL) {
            value = max(value, 1+dosomething(ptr->right));
        }
    }
    return value;
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

    cout << dosomething(root);

    //int diff = INT_MIN;
    //max_diff(root, diff);
    //maxDifference(root, diff);
    //cout << diff;


    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

