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


struct Node *reverse_k_groups(struct Node *head, int k) {
    struct Node *current = head, *previous = NULL, *next = NULL;
    int count = 0;

    while(count++ < k && current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    if(next != NULL) {
        head->next = reverse_k_groups(next, k);
    }
    return previous;
}

void push(struct Node **head, int data) {
    struct Node *node = new (struct Node);
    node->data = data;
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

int main() {
    clock_t tStart = clock();
    struct Node *head = NULL;
    for(int i = 0; i < 10; i++) {
        push(&head, i);
    }

    print_list(head);
    head = reverse_k_groups(head, 3);
    print_list(head);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
