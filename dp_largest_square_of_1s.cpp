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

int minimium(int a, int b, int c, int d) {
    int m[] = {a, b, c, d};
    int x = INT_MAX;
    for(int i = 0; i < 4; i++) {
        x = min(x, m[i]);
    }
    return x;
}
int main() {
    clock_t tStart = clock();

    int r = 4, c = 5;
    int a[][5] = {{1,1,0,1,0}, {0,1,1,1,0}, {1,1,1,1,0}, {0,1,1,1,1}};
    int result = 0;
    int s[4][5];
    for(int i = 0; i < r; i++)
        s[i][0] = a[i][0];
    for(int j = 0; j < c; j++)
        s[0][j] = a[0][j];


    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
        cout << "\n";
    for(int i = 1; i < r; i++) {
        for(int j = 1; j < c; j++) {
            if(a[i][j] == 1) {
                s[i][j] = minimium(s[i][j-1], s[i-1][j-1], s[i-1][j], INT_MAX) + 1;
                cout << s[i][j];
            } else {
                s[i][j] = 0;
            }
        }
    }


    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }
        cout << "\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
        cout << "\n";
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

