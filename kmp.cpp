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

vector<int> compute_lps(string pattern) {
    int length = pattern.length();
    vector<int> lps(length);
    int i = 1;
    int index = 0;
    while(i < length) {
        if(pattern[i] == pattern[index]) {
            lps[i] = index + 1;
            index++;
            i++;
        } else {
            if(index != 0) {
                index = lps[index-1];
            } else {
                i++;
            }
        }
    }
    return lps;
}

bool kmp(string text, string pattern) {
    int i = 0;
    int j = 0;
    cout << text.length() << "\n";
    vector<int> lps = compute_lps(pattern);
    while(i < text.length() && j < pattern.length()) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if(j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    cout << i << " " << j << "\n";
    if(j == pattern.length()) return true;
    return false;
}

int main() {
    clock_t tStart = clock();

    string text = "abcxabcdabcdabcy";
    string pattern = "abcy";
    cout << kmp(text, pattern);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
