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

int p(vector<int> &A, int B) {
    vector<bool> v(100000, true);
    set<int> all;
    set<int> primes;
    v[0] = v[1] = false;
    v[2] = v[3] = true;

    for(int i : A) {
        all.insert(i);
    }
    for(int i = 2; i< v.size(); i++) {
        if(v[i] == true) {
            primes.insert(i);
            for(int j = i*2; j < v.size(); j = j+i) {
                v[j] = false;
            }
        }
    }
    int c = 0;
    for(auto i: all) {
        
        if(B%i == 0 && primes.find(i) != primes.end()) {
            c+=1;
        }
    }
    return c;

}

int main() {
    clock_t tStart = clock();

    vector<int> A{315, 955, 544, 389, 877, 52, 128, 852, 328, 781, 71, 467, 135, 713, 545, 529, 121, 192, 144, 262, 928, 950, 766, 405, 934, 447, 786, 465, 831, 435, 307, 512, 662, 378, 33, 988, 341, 570, 818, 114, 49, 522, 700, 81, 392, 237, 304, 916, 581, 413, 659, 409, 258, 807, 633, 946, 233, 466, 582, 576, 371, 809, 235, 890, 958, 403, 697};

    int B = 733;
    cout << p(A, B);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
