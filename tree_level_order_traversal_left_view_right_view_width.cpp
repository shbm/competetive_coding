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


    template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

    template <typename T>
ostream& operator<<(ostream& os, const set<T>& v)
{
    os << "[";
    for (auto it : v) {
        os << it;
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "]\n";
    return os;
}

    template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v)
{
    os << "(";
    os << v.first << ", "
        << v.second << ")";
    return os;
}

    template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v)
{
    for (auto it : v)
        os << it.first << " : "
            << it.second << "\n";

    return os;
}

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node *new_node(int data) {
    return new Node(data);
}

void inorder(Node *r) {
    if(r == nullptr) {
        return;
    }
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void left_view(Node *root) {
    if(root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        int i = 0;
        while(i++ < size) {
            Node *curr = q.front();
            q.pop();
            if(i == 1)
                cout << curr->data << " ";
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
    }
}

void right_view(Node *root) {
    if(root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        int i = 0;
        while(i++ < size) {
            Node *curr = q.front();
            q.pop();
            if(i == size)
                cout << curr->data << " ";
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
    }
}

int max_width(Node *root) {
    if(root == nullptr) {
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    int max_width = 0;
    while(!q.empty()) {
        int width = q.size();
        max_width = max(max_width, width);
        while(width--) {
            Node *curr = q.front();
            q.pop();
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
    }
    return max_width;
}


void level_order_tree_traversal(Node *root) {
    if(root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);
    int level = 0;
    int dir = 1;
    vector<vector<int>> r;
    while(!q.empty()) {
        int size = q.size();
        vector<int >v;
        while(size--) {
            Node *curr = q.front();
            q.pop();
            v.push_back(curr->data);
            if(curr->right) {
                q.push(curr->right);
            }
            if(curr->left) {
                q.push(curr->left);
            }
        }
        dir = !dir;
        if(dir) {
            r.push_back(v);
        }
        if(!dir) {
            reverse(v.begin(), v.end());
            r.push_back(v);
        }
    }
    cout << r;
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
    inorder(root);
    cout << "\n";
    cout << "LEVEL ORDER TRAVERSAL: ";
    level_order_tree_traversal(root);
    cout << "\n";
    cout << "LEFT VIEW: ";
    left_view(root);
    cout << "\n\n";
    cout << "RIGHT VIEW: ";
    right_view(root);
    cout << "\n" << "MAX WIDTH: " << max_width(root);
    cout << "\n\n";


    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
