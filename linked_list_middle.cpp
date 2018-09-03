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
    struct Node* next;
};

// pushing all the data in the beginning of the list
void push(struct Node** head, int data) {

    // create a new pointer and allocate it the size of the Node
    // This will be the new "block"
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;

    // Since the new "block" is added to the beginng, assign the new node to the beginning
    *head = new_node;
}

void print_list(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
}

// Using the method of the fast pointer  and the slow pointer to 
// print the middle of a linked list
void print_middle(struct Node* head) {
    struct Node *slow = head;
    struct Node *fast = head;

    // IMPORTANT: fast->next != NULL is used in case the length of the
    // linked list is ODD.
    // If the linked list length is ODD the fast->next->next will lead to SEGFAULT
    // since it doesn't exist
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << " --- " << slow->data;
}

int main() {
    clock_t tStart = clock();

    struct Node *head = NULL;
    int a[] = {1,2,3,4,5,6,7,8};
    for (int i : a) {
        push(&head, i);
    }
    print_list(head);
    print_middle(head);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
