#include <stdio.h>
#include <queue>
#include <sstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <time.h>
#include <bitset>
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

struct Node {
    struct Node *next;
    int data;
    Node(int x): data(x), next(NULL) {};
};

void push(Node *&head, int data) {
    struct Node *new_node = new Node(data);
    new_node->next = head;
    head = new_node;

}

int main() {
    clock_t tStart = clock();

    struct Node *head = NULL;
    for(int i = 0; i < 10; i++) {
        push(head, i);
    }

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
