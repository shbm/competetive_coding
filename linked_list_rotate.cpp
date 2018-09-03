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

void rotate(struct Node **head_ref, int k) {
    if(k == 0) return;

    struct Node *current = *head_ref;

    int count = 1;
    while(count++ < k && current != NULL) {
        current = current->next;
    }
    if(current == NULL) return;

    struct Node *kth_node = current;

    while(current->next != NULL)
        current = current->next;

    current->next = *head_ref;
    *head_ref = kth_node->next;

    kth_node->next = NULL;
}

void push(struct Node **head_ref, int data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print_list(struct Node *head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    clock_t tStart = clock();

    struct Node *head = NULL;
    for(int i = 0; i< 10; i++) {
        push(&head, i);
    }
    print_list(head);
    rotate(&head, 4);
    print_list(head);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
