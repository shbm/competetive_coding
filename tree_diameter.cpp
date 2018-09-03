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
    Node *left;
    Node *right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

Node *new_node(int data) {
    return new Node(data);
}

void insert(Node *&root, int data) {
    if(root == nullptr) {
        root = new_node(data);
        return;
    }
    if(root->data > data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

void inorder(Node *&root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void make_balanced_tree(Node *&root, int a[], int low, int high) {
    if (low > high) {
        return;
    }
    int mid = (low+high)/2;
    root = new_node(a[mid]);
    make_balanced_tree(root->left, a, low, mid-1);
    make_balanced_tree(root->right, a, mid+1, high);
}

int height(Node *root) {
    if(root == nullptr) {
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
}

int diameter(Node *root, int &d) {
    if(root == nullptr) {
        return 0;
    }

    int left_height = diameter(root->left, d);
    int right_height = diameter(root->right, d);

    int max_diameter = left_height + right_height + 1;

    d = max(d, max_diameter);

    int m = max(left_height, right_height) + 1;
    printf("\nDAIAMETER(%d, %d): returns -> %d", root->data, d, m);
    return m;
}

int main() {
    clock_t tStart = clock();
    Node *root = nullptr;
    int a[] = {8,7,4,7,23,74,85,234,75};
    int len = sizeof(a)/sizeof(a[0]);
    sort(a, a+len);
    make_balanced_tree(root ,a, 0, len-1);
    inorder(root);
    cout << height(root);
    int d = 0;
    cout << "DIAMETER: " << diameter(root, d) << "\n";

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
