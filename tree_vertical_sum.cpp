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

void printTop(Node *root, int distance, map<int, int> &map) {
    if(root == nullptr) return;

    map[distance] += root->data;

    printTop(root->left, distance-1, map);
    printTop(root->right, distance+1, map);
}

void printTop(Node *root) {
    // distance, data, level
    map<int, int> map;

    printTop(root, 0, map);
    for(auto it: map) {
        printf("map[%d] = %d\n", it.first, it.second);
    }
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

    printTop(root);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}