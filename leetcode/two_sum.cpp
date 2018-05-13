#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> solveSums(int *n, int size, int target) {
    map<int, int> hash;
    vector<int> v;
    for(int i = 0; i < size; i++) {
        hash[n[i]] = i;
        int complement = target - n[i];
        if(hash.find(complement) != hash.end()) {
            v.push_back(hash[n[i]]);
            v.push_back(hash[complement]);
            return v;
        }
    }
    return v;
}

int main() {

    int nums[] = {2, 7, 11, 15}, target = 18;
    vector<int> v = solveSums(nums, sizeof(nums)/sizeof(int), target);
    for(int i = 0; i<v.size(); i++)
        cout << nums[v[i]] << "\n";
    return 0;
}
