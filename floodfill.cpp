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

#define m 10
#define n 10

// Check if the matrix cell is valid or not, i.e can it be pushed in the queue for BFS or not
bool isvalid(char matrix[m][n], int x, int y, char target) {
    bool r = (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == target);
    return r;
}

// floodfill by BFS
void floodfill(char matrix[m][n], int x, int y, char replacement) {
    // target is what cell character to replace
    char target = matrix[x][y];

    // for traversing all the 8 directions
    int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // keeping a track fo processed cell.
    // redundant but a good practice
    bool processed[m][n];

    queue<pair<int, int> > q;
    q.push(make_pair(x, y));


    // replace the intitial cell with the given character
    matrix[x][y] = replacement;

    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        int x = node.first, y = node.second;
        matrix[x][y] = replacement;
        // check for all the eight adjacent cells
        // append the immediate neighbour to the queue
        for(int i = 0; i < 8; i++) {
            if(isvalid(matrix, x+row[i], y+col[i], target)) {
                processed[x][y] = true;
                q.push(make_pair(x+row[i], y+col[i]));
            }
        }
    }
}

int main() {
    clock_t tStart = clock();
    char mat[10][10] = {
        { 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G' },
        { 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'X', 'X', 'X' },
        { 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'X', 'X', 'X' },
        { 'W', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'X' },
        { 'W', 'R', 'R', 'R', 'R', 'R', 'G', 'X', 'X', 'X' },
        { 'W', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'X' },
        { 'W', 'B', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'X' },
        { 'W', 'B', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X' },
        { 'W', 'B', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X' },
        { 'W', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
    };

    int x = 3, y = 9;
    char replacement = 'Z';
    floodfill(mat, x, y, replacement);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
