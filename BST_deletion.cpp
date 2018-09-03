#include <stdio.h>
#include <queue>
#include <sstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <time.h>
#include <bitset>
#include <climits>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int d) : data(d), left(NULL), right(NULL) {};
};

Node * new_node(int data) {
    Node *n = new Node(data);
    return n;
}

void insert(Node *&root, int data) {
    if(!root) {
        root = new_node(data);
        return;
    }
    if(data > root->data) {
        insert(root->right, data);
    } else {
        insert(root->left, data);
    }
}

Node *maxkey(Node *root) {
    while(!root->right) {
        root=root->right;
    }
    return root;
}

void del(Node *&root, int data) {
    if(!root) return ;
    if(root->data > data) {
        del(root->left, data);
    } else if(root->data < data) {
        del(root->right, data);
    } else {
        if(!root->left && !root->right) {
            delete root;
            root = NULL;
        }
        else if(root->left && root->right) {
            Node *predecessor = maxkey(root->left);
            root->data = predecessor->data;
            del(root->left, predecessor->data);
        } else {
            Node *child = root->left ? root->left : root->right;
            Node *curr = root;
            root = child;
            delete curr;
        }
    }

}

void inorder(Node *root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    clock_t tStart = clock();

    vector<int> v;
    Node *root = NULL;

    int keys[] = { 15, 10, 20, 8, 12, 25 };

    for (int key : keys)
        insert(root, key);

    inorder(root);
    del(root,12);
    cout << "\n";
    inorder(root);
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
