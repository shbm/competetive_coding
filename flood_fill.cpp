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

#define ROW 8
#define COL 8

int COUNT;
void floodfill(int x, int y, int M[ROW][COL], int prevColor, int newColor) {
    if(x < 0 && x >= ROW && y < 0 && y >= COL)
        return;
    if(M[x][y] != prevColor)
        return;

    M[x][y] = newColor;

    COUNT++;

    floodfill(x-1, y+0, M, prevColor, newColor);
    floodfill(x+0, y+1, M, prevColor, newColor);
    floodfill(x+1, y+0, M, prevColor, newColor);
    floodfill(x+0, y-1, M, prevColor, newColor);
}

int main() {
    clock_t tStart = clock();

    int M[ROW][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1},
    };
    COUNT = 0;

    int startX = 4, startY = 4;
    int prevColor = 2;
    int newColor = 3;
    floodfill(startX, startY, M, prevColor, newColor);
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            cout << M[i][j];
        }
        cout << "\n";
    }

    cout << COUNT;
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
