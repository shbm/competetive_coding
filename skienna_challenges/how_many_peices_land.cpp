#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

map<int, int> fact_map;

int fact(int n) {
    if(n == 1 || n == 0) {
        return fact_map[n];
    } else {
        if(fact_map.find(n) != fact_map.end()) {
            return fact_map[n];
        }
        fact_map[n] = n*fact(n-1);
        return fact_map[n];
    }
}

int ncr(int n, int r) {
    int a = int(fact(n));
    int b = int(fact(r));
    int c = int(fact(n-r));
    int x = int( a / ( int(b) * int(c) ) );
    printf("ncr( %d, %d ) = %d\n", n, r, x);
    return x;
}

int land_peices(int n) {
    return ncr(n, 4) + ncr(n, 2) + 1;
}

int main() {
    fact_map[0] = fact_map[1] = 1;
    int n = land_peices(8);

    printf("%d", n);
    return 0;
}
