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

void sum(struct Node *n1, struct Node *n2, struct Node **s) {
    int carry = 0;
    while(n1 != NULL && n2 != NULL) {
        int d = (n1->data + n2->data)%10;
        carry = (n1->data + n2->data)/10;
    }
}

void push(struct Node **head_ref, int data) {
    struct Node *h = new (struct Node);
    h->next = *head_ref;
    h->data = data;
    *head_ref = h;
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
    srand(time(0));
    struct Node *n1 = NULL;
    struct Node *n2 = NULL;
    struct Node *s = NULL;
    for(int i = 0; i < 5; i++) {
        push(&n1, rand()%10);
        push(&n2, rand()%10);
    }
    print_list(n1);
    print_list(n2);
    sum(n1, n2, &s);
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
