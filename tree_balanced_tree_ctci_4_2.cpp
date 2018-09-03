#include <iostream>
#include <algorithm>
using namespace std;
 
// Data structure to store a Binary Search Tree node
struct Node {
    int data;
    Node *left, *right;
};
 
// Function to create a new binary tree node having given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
 
    return node;
}
 
// Function to perform in-order traversal of the tree
void inorder(Node* root)
{
    if (root == nullptr)
        return;
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
// Recursive function to insert an key into BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node an return it
    if (root == nullptr)
        return newNode(key);
 
    // if given key is less than the root node, recurse for left subtree
    if (key < root->data)
        root->left = insert(root->left, key);
 
    // if given key is more than the root node, recurse for right subtree
    else
        root->right = insert(root->right, key);
 
    return root;
}
 
// Function to construct balanced BST from given sorted array
// Note - root of the tree is passed by reference here
void convert(int keys[], int low, int high, Node* &root)
{
    // base case
    if (low > high)
        return;
 
    // find middle element of current range
    int mid = (low + high) / 2;
 
    // construct a new node from mid element and assign it to root
    root = newNode(keys[mid]);
 
    // left subtree of root will be formed by keys less than mid element
    convert(keys, low, mid - 1, root->left);
 
    // right subtree of root will be formed by keys less than mid element
    convert(keys, mid + 1, high, root->right);
}
 
// Function to construct balanced BST from given unsorted array
Node* convert(int keys[], int n)
{
    // sort the keys first
    sort(keys, keys + n);
 
    // construct balanced BST
    Node *root = nullptr;
    convert(keys, 0, n-1, root);
 
    // return root node of the tree
    return root;
}
 
// Construct balanced BST from given keys
int main()
{
    // input keys
    int keys[] = { 7,6,5,4,3,2,1 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    // construct balanced binary search tree
    Node* root = convert(keys, n);
 
    // print the keys in in-order fashion
    inorder(root);
 
    return 0;
}
