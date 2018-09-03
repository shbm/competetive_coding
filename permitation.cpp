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

template <typename T>
ostream& operator<<(ostream& os, const set<T>& v)
{
    os << "[";
    for (auto it : v) {
        os << it;
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "]\n";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v)
{
    os << "(";
    os << v.first << ", "
        << v.second << ")";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v)
{
    for (auto it : v)
        os << it.first << " : "
            << it.second << "\n";

    return os;
}

vector<string> v;

void all_permutation(string s, string chosen) {
    // base case if the string is empty and all the permuataions have been generated
    if(s.empty()) {
        v.push_back(chosen);
        return;
    } else {
        for(int i = 0; i < s.size(); i++) {

            //iterate through the loop and keep extracting characters
            char c = s[i];

            // append the character to the end of the suffix(choosen)
            chosen += c;

            //remove the extraceted character from the string
            s.erase(i, 1);

            //permute over the new extracted character and the new string
            all_permutation(s, chosen);

            // after the permuation make the string to it's initial state
            // insert back the removed character
            s.insert(i, 1, c);

            // after permutation make the chosen suffix to it's initial state
            // remove last character
            chosen.erase(chosen.length() - 1, 1);
        }
    }
}

string _next_permutation(string s) {
    int i = s.size() - 1;
    //while(i >= 0 && s[i-1] >= s[i]) {
        //i--;
    //}

    while(i>=0) {
        if(s[i-1] <= s[i]) {
            break;
        } else {
            i--;
        }
    }
    int pivot = i-1;
    int j = s.size() - 1;
    while(s[j] <= s[pivot]) {
        j--;
    }

    swap(s[j], s[pivot]);

    reverse(s.begin()+i, s.end());
    return s;
}

int main() {
    clock_t tStart = clock();

    string s = "shub";
    all_permutation(s, "");
    s = "shub";
    cout << v << endl;
    
    do {
        cout << s << " ";
    } while(next_permutation(s.begin(), s.end()));

    cout << "\n" << _next_permutation("shub");

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
