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
#include <climits>

using namespace std;

int aa(const string A) {

    istringstream s(A);
    string str;

    while(getline(s, str, ' ')) {
        break;
    }
    bool minus = false;
    if(str[0] == '-' || str[0] == '+') {
        if(str[0] == '-')
            minus = true;
        str = string(str.begin()+1, str.end());
    }
    cout << str << "\n";
    int n = 0;
    while(str.length()) {
        if(!isalpha(str[0])) {
            cout << "\n" << "break" << "\n";
            break;
        }
        int d = int(str[0]-'0');
        n = n * 10 + d;
        str = string(str.begin() + 1, str.end());
        cout << str << "\n";
    }

    cout << str << "\n";
    if(minus) n = -n;

    return n;
}


int main() {
    clock_t tStart = clock();

    cout <<
    aa("-9 2704");

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
