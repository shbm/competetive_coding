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

void push(struct Node** head, int data) {

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
}

struct Node *middle_node(struct Node* head, bool &odd) {
    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *prev = NULL;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast) {
        odd = true;
    }
    prev->next = NULL;
    cout << "middle-> " << slow->data << "\n";
    return slow;
}

void reverse(struct Node **head) {
    struct Node *next = NULL;
    struct Node *current = *head;
    struct Node *previous = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }
    *head = previous;
}

bool compare(Node *a, Node *b) {
    if(a == NULL && b == NULL) {
        return true;
    }
    if( a != NULL)
        cout << "condition_check -> a:" << a->data;
    if(b != NULL)
        cout << "b: "<< b->data << "\n";
    bool c = a && b && (a->data == b->data) && compare(a->next, b->next);
    cout << "c -> " << c << "\n";
    return c;
}

bool palindrome(Node *head) {
    if(head == NULL) return true;
    bool odd = false;

    Node *mid = middle_node(head, odd);

    if(odd)
        mid = mid->next;

    reverse(&mid);
    cout << "ODD-> " << odd << "\n";
    return compare(head, mid);
}

int main() {
    clock_t tStart = clock();

    struct Node *head = NULL;
    int a[] = {1,2,3,4,5,4,3,2,1,0};
    for (int i : a) {
        push(&head, i);
    }
    print_list(head);
    cout << "Palindrome:" << palindrome(head) << "p\n";
    print_list(head);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
