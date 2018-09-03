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
    struct Node *next;
};

struct Node *tail = NULL;

void print_list(struct Node *head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "\n";
}

void push(struct Node **head_ref, int data) {
    struct Node *n = new (struct Node);
    n->data = data;
    n->next = *head_ref;
    *head_ref = n;
}

void append(struct Node *head, int data) {
    struct Node *n = new (struct Node);
    n->data = data;
    n->next = NULL;
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = n;
}

int get_pivot(struct Node *head_ref) {
    return head_ref->data;
}

void partition_pivot(struct Node *head_ref, struct Node **piv, int pivot) {
    push(piv, pivot);
    while(head_ref != NULL) {
        int d = head_ref->data;
        if(d <= pivot) {
            push(piv, d);
        } else {
            append(*piv, d);
        }
        head_ref = head_ref->next;
    }
}


int main() {
    clock_t tStart = clock();
    srand(time(0));

    struct Node *head = NULL;
    for(int i = 0; i< 10; i++) {
        push(&head, rand()%100);
    }
    append(head, 10);
    print_list(head);
    int p = get_pivot(head);
    cout << p << "\n";

    struct Node *piv = NULL;
    partition_pivot(head, &piv, p);
    print_list(piv);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
