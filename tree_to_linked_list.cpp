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

bool ancestor(Node *root, int node) {
    if(!root) return false;
    if(root->data == node) {
        return true;
    }

    if(ancestor(root->left, node) || ancestor(root->right, node)) {
        cout << root->data;
        return true;
    }
    return false;
}

void tree_to_linked_list(Node *root, Node *&head, Node *&prev) {
    if(!root) return;
    if(!prev) {
        head = root;
    } else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    tree_to_linked_list(root->right, head, prev);
    tree_to_linked_list(root->left, head, prev);
    tree_to_linked_list(root->right, head, prev);
}

//void tree_to_linked_list(Node *root, Node *&head) {
    //if(!root) return;
    //tree_to_linked_list(root->left, head);

    //static Node *prev = NULL;
    //if(prev == NULL) {
        //head = root;
    //} else {
        //prev->right = root;
        //root->left = prev;
    //}
    //prev = root;
    //tree_to_linked_list(root->right, head);
//}

int main() {
    clock_t tStart = clock();

    /*
           1
          / \
        /     \
       2       3
      / \     /  \
     0   4   5    6
            / \
           7   8
    */
    Node *root = new_node(1);
    root->left = new_node(2);
    root->left->left = new_node(0);
    root->right = new_node(3);
    root->left->right = new_node(4);
    root->right->left = new_node(5);
    root->right->right = new_node(6);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(8);

    Node *head = NULL;
    Node *prev = NULL;
    tree_to_linked_list(root, head, prev);

    while(head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << "\n";

    //ancestor(root, 7);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


