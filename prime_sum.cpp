#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <time.h>
#include <climits>

using namespace std;

void primesum(int A) {
    int N = A;
    vector<bool> primes(N+1, true);
    set<int> p;
    p.insert(2);
    primes[0] = primes[1] = false;
    for(int i = 2; i*i<=N; i++) {
        if(primes[i] == true) {
            p.insert(i);
            for(int j = i*2; j <= N; j = j + i) {
                primes[j] = false;
            }
        }
    }
    for(int i =0; i < N+1; i++) {
        if(primes[i] == 1) {
            cout << i << " ";
        }
    }
    cout << "\n";
    vector<int> sol;
    for(int i = 0; i < N+1; i++) {
        if(primes[i] == true && primes[A-i] == true && A-i != i) {
            sol.push_back(i);
            sol.push_back(A-i);
            return sol;
        }
    }
}


int main() {
    clock_t tStart = clock();

    primesum(10);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

