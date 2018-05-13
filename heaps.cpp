#include <stdio.h>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) for (int i = a; i < b; i++)

struct PriorityQueue {
private:
    vector<int> A;

    int PARENT(int i) {
        return (i-1)/2;
    }

    int LEFT(int i) {
        return (2*i+1);
    }

    int RIGHT(int i) {
        return (2*i+2);
    }

    void heapify_down(int i) {
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        if (left < size() && A[left] > A[largest]) {
            largest = left;
        }
        if (right < size() && A[right] > A[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(A[i], A[largest]);
            heapify_down(largest);
        }
    }

    void heapify_up(int i) {
        if (i && A[PARENT(i)] < A[i]) {
            swap(A[PARENT(i)], A[i]);
            heapify_up(A[PARENT(i)]);
        }
    }
public:
    int size() {
        return A.size();
    }

    void print_heap() {
        for(const auto &i: A) {
            cout << " " << i;
        }
        cout << "\n";
    }

    bool empty() {
        return A.size() == 0;
    }

    void push(int key) {
        A.push_back(key);

        int index = size() - 1;
        heapify_up(index);
    }

    void pop() {
        try {
            if (size() == 0) {
                throw out_of_range("Underflow");
            }

            A[0] = A.back();
            A.pop_back();

            heapify_down(0);
        } catch(const out_of_range& err) {
            cout << err.what();
        }
    }

    int top() {
        try {
            if (size() == 0) {
                throw out_of_range("Underflow");
            }

            return A[0];
        } catch(const out_of_range& err) {
            cout << err.what();
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.push(1);
    pq.push(21);
    pq.push(11);
    pq.push(41);
    pq.print_heap();
    while(!pq.empty()) {
        cout << " " <<pq.top();
        pq.pop();
    }
    return 0;
}
