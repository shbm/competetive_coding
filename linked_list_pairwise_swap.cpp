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
    Node *next;
    Node(int n): data(n), next(NULL) {}
};

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void pairwise_swap(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL && temp->next != NULL) {
        swap(&temp->data, &temp->next->data);
        temp = temp->next->next;
    }
}

void push(struct Node **head, int data) {
    Node *node = new Node(data);
    node->next = *head;
    *head = node;
}

void print_list(struct Node *head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "\n";
}

struct cmp
{
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};


Node* mergeKLists(vector<Node*> &A, int k) {
    priority_queue<Node *, vector<Node *>, cmp> pq;
    Node *h = new Node(0);
    Node *head = h;
    for(int i = 0; i < k; i++) {
        pq.push(A[i]);
    }
    while(pq.size()) {
        Node *temp = pq.top();
        pq.pop();
        if(temp->next)
            pq.push(temp->next);
        head->next = temp;
        head = head->next;
    }
    return h->next;
}


int main() {
    clock_t tStart = clock();

    struct Node *head1 = NULL;
    for(int i = 10; i > 0; i--) {
        push(&head1, i*2);
    }
    struct Node *head2 = NULL;
    for(int i = 15; i > 0; i--) {
        push(&head2, i*3);
    }
    struct Node *head3 = NULL;
    for(int i = 20; i > 0; i--) {
        push(&head3, i*4);
    }

    //print_list(head);
    //pairwise_swap(head);
    print_list(head1);
    cout << "\n";
    print_list(head2);
    cout << "\n";
    print_list(head3);
    cout << "\n";

    vector<Node *> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);
    for(Node * i: lists) {
        Node *head = i;
        while(head) {
            cout << head->data <<" ";
            head = head->next;
        }
        cout << "\n";
    }
    
    Node *head = mergeKLists(lists, 3);
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
