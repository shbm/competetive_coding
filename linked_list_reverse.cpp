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
    struct Node * next;
};

// It's all a game of pointers.
// Make a mental model of how to manipulate these "arrows"
// basically the next arrow will
// (*head) --> 1 -> 2 -> 3 -> 4 -> 5

void reverse(struct Node **head_ref) {
    struct Node *next = NULL, *previous = NULL, *current = *head_ref;
    while(current != NULL) {
        // change next to current->next
        next = current->next;
        // reverse the arrow
        current->next = previous;

        // move the two pointers forward
        previous = current;
        current = next;
    }
    *head_ref = previous;
}

void push(struct Node **head_ref, int data) {
    struct Node *new_node = (struct Node *) malloc(sizeof (struct Node));
    new_node->next = *head_ref;
    new_node->data = data;
    *head_ref = new_node;
}

void print_list(struct Node *head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
}

int main() {
    clock_t tStart = clock();
    struct Node *node = NULL;
    for(int i = 0; i< 10; i++) {
        push(&node, i);
    }

    print_list(node);
    reverse(&node);
    cout << "\n";
    print_list(node);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
