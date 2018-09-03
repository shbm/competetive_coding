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

priority_queue<int> smaller_half_max_heap;
priority_queue<int, vector<int>, greater<int>> larger_half_min_heap;

void add_number(int number) {
    if(smaller_half_max_heap.size() == 0 || number < smaller_half_max_heap.top()) {
        smaller_half_max_heap.push(number);
    } else {
        larger_half_min_heap.push(number);
    }
}

void balance_heaps() {
    int size_max_heap = smaller_half_max_heap.size();
    int size_min_heap = larger_half_min_heap.size();
    if(size_max_heap > size_min_heap + 1) {
        int number = smaller_half_max_heap.top();
        smaller_half_max_heap.pop();
        larger_half_min_heap.push(number);
    }
    if(size_min_heap > size_max_heap + 1) {
        int number = larger_half_min_heap.top();
        larger_half_min_heap.pop();
        smaller_half_max_heap.push(number);
    }
}

double get_median() {
    if(smaller_half_max_heap.size() == larger_half_min_heap.size()) {
        return (smaller_half_max_heap.top() + larger_half_min_heap.top())/2.0;
    }
    else {
        int size_max_heap = smaller_half_max_heap.size();
        int size_min_heap = larger_half_min_heap.size();
        if(size_max_heap > size_min_heap) {
            return smaller_half_max_heap.top();
        } else {
            return larger_half_min_heap.top();
        }
    }
}

vector<double> get_medians(vector<int> a) {
    vector<double> medians;
    for(auto &i:a) {
        add_number(i);
        balance_heaps();
        medians.push_back(get_median());
    }
    return medians;
}

int main() {
    clock_t tStart = clock();

    vector<int> a {5,15,10,20,3};
    vector<double> results;
    results = get_medians(a);

    for(auto &i : results) {
        cout << i << " ";
    }
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
