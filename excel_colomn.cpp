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

void printString(int A) {

    string sol="";
    int d;
    while(A) {
        int d = A%26;
        char c = char(64+d);
        sol = c + sol;
        A/=26;
    }


    cout << sol;
    cout << "\n";

}

int main() {
    clock_t tStart = clock();

        printString(26);
    printString(51);
    printString(52);
    printString(80);
    printString(676);
    printString(702);
    printString(705);

printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
