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
    Node (int d): data(d), left(nullptr), right(nullptr) {}
};

void inorder(Node *root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *new_node(int data) {
    return new Node(data);
}

void make_balanced_tree(Node *&root, int a[], int low, int high) {
    if(low > high) return;

    int mid = (low+high)/2;
    root = new_node(a[mid]);
    make_balanced_tree(root->left, a, low, mid-1);
    make_balanced_tree(root->right, a, mid+1, high);
}

int height(Node *r) {
    if(r == nullptr) return 0;
    return 1+max(height(r->left), height(r->right));
}

void convert_to_mirror(Node *r) {
    if(r == nullptr) return;
    convert_to_mirror(r->left);
    convert_to_mirror(r->right);
    swap(r->left, r->right);
}

int main() {
    clock_t tStart = clock();

    int a[] = {5,3,8,23,75,12,5,4,25,86,29};
    int length = sizeof(a)/sizeof(int);
    sort(a, a+length);
    Node *root = nullptr;
    make_balanced_tree(root, a, 0, length-1);
    inorder(root);
    cout << "HEIGHT: " << height(root) << "\n";
    convert_to_mirror(root);
    inorder(root);
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
