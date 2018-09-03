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

int g = 1;
void generate_parenthesis(string pattern, int open_brackets, int closed_brackets) {

    //check if all the open and closed brackets have been used up or not
    if(open_brackets == 0 && closed_brackets == 0) {

        // print the generated pattern if all the opening and closing brackets have been used
        cout << g++ << " - " << pattern << "\n";
        return;
    }

    // if there are any opening brackets then use them
    if(open_brackets) {
        // if opening bracket is used then decrement the value of open_brackets by 1
        generate_parenthesis(pattern + "(", open_brackets-1, closed_brackets);
    }

    // if there are any closed brackets more than the open brackets
    if (closed_brackets > open_brackets) {

        // use the closing bracket and decrement the number
        generate_parenthesis(pattern + ")", open_brackets, closed_brackets-1);
    }
}

int main() {
    clock_t tStart = clock();

    int n = 6;
    generate_parenthesis("", n, n);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
